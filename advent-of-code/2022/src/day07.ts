import { getInput } from "../lib.ts";

interface Directory {
  name: string;
  items: FileItem[];
  parent: Directory | null;
}

interface File {
  size: number;
  name: string;
}

type FileItem = File | Directory;

function isDirectory(f: FileItem): f is Directory {
  return "items" in f && "parent" in f;
}

function cd(path: string, currentPath: Directory, root: Directory) {
  switch (path) {
    case "/": {
      return root;
    }
    case "..": {
      return currentPath.parent ?? root;
    }
    default: {
      return currentPath.items.filter(isDirectory).find((dir) =>
        dir.name === path
      ) ?? root;
    }
  }
}

function pushItem(currentPath: Directory, item: string) {
  const [info, name] = item.split(" ");

  let fileItem: FileItem;
  if (info === "dir") {
    fileItem = { name, items: [], parent: currentPath };
  } else {
    fileItem = { name, size: parseInt(info, 10) };
  }
  currentPath.items.push(fileItem);
}

function runCommand(lines: string[], currentPath: Directory, root: Directory) {
  const cmdLine = lines.shift()?.split(" ");
  if (!cmdLine) return currentPath;

  switch (cmdLine[0]) {
    case "cd": {
      currentPath = cd(cmdLine[1], currentPath, root);
      break;
    }
    case "ls": {
      lines.map((item) => pushItem(currentPath, item));
      break;
    }
  }
  return currentPath;
}

function calculateDirectorySize(dir: Directory, res: number[]): number {
  const total = dir.items
    .map((item) => {
      if (isDirectory(item)) {
        return calculateDirectorySize(item, res);
      } else {
        return item.size;
      }
    })
    .reduce((a, b) => a + b, 0);
  if (total !== 0) res.push(total);
  return total;
}

function getDirectorySizes() {
  const root: Directory = { name: "/", items: [], parent: null };
  let currentPath = root;
  getInput(Deno.args[0])
    .split("$ ")
    .slice(1)
    .map((line) => line.trim().split("\n"))
    .map((line) => {
      currentPath = runCommand(line, currentPath, root);
    });

  const directorySizes: number[] = [];
  calculateDirectorySize(root, directorySizes);
  return directorySizes;
}

function part1() {
  return getDirectorySizes()
    .filter((sum) => sum <= 100000)
    .reduce((a, b) => a + b, 0);
}

function part2() {
  const directorySizes = getDirectorySizes().sort((a, b) => a - b);
  const rootSize = directorySizes.at(-1) ?? 0;
  const toFreeUpSpace = rootSize - 40000000;

  return directorySizes.find((size) => size >= toFreeUpSpace);
}

console.log(part1());
console.log(part2());
