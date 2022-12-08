import { getInput } from "../lib.ts";

function isVisible(trees: number[][], y: number, x: number): number {
  const height = trees.length;
  const width = trees[0].length;

  const dy = [0, 0, 1, -1];
  const dx = [1, -1, 0, 0];
  for (let i = 0; i < 4; ++i) {
    for (let ny = y + dy[i], nx = x + dx[i];; ny += dy[i], nx += dx[i]) {
      if (ny < 0 || ny >= height || nx < 0 || nx >= width) {
        return 1;
      }
      if (trees[y][x] <= trees[ny][nx]) {
        break;
      }
    }
  }
  return 0;
}

function getScenicScore(trees: number[][], y: number, x: number): number {
  let score = 1;
  const height = trees.length;
  const width = trees[0].length;

  const dy = [0, 0, 1, -1];
  const dx = [1, -1, 0, 0];
  for (let i = 0; i < 4; ++i) {
    let visibleTrees = 0;
    for (
      let ny = y + dy[i], nx = x + dx[i];
      ny >= 0 && ny < height && nx >= 0 && nx < width;
      ny += dy[i], nx += dx[i]
    ) {
      visibleTrees++;
      if (trees[y][x] <= trees[ny][nx]) {
        break;
      }
    }
    score *= visibleTrees;
  }
  return score;
}

function getTrees() {
  return getInput(Deno.args[0])
    .trim()
    .split("\n")
    .map((line) =>
      line
        .split("")
        .map((height) => parseInt(height, 10))
    );
}

function part1() {
  const trees = getTrees();
  const visibles = trees.map((line, y) =>
    line.map((_, x) => isVisible(trees, y, x))
  );
  return visibles.flat().reduce((a, b) => a + b, 0);
}

function part2() {
  const trees = getTrees();
  const scores = trees.map((line, y) =>
    line.map((_, x) => getScenicScore(trees, y, x))
  );
  return Math.max(...scores.flat());
}

console.log(part1());
console.log(part2());
