import { getInput } from "../lib.ts";

function solution(part: number) {
  const queue: number[][] = [];
  const end = [0, 0];
  const map = getInput(Deno.args[0])
    .trim()
    .split("\n")
    .map((line, y) =>
      line
        .split("")
        .map((c, x) => {
          if (c === "S") {
            queue.push([y, x, 0]);
            c = "a";
          } else if (c === "a" && part === 2) {
            queue.push([y, x, 0]);
          } else if (c === "E") {
            end[0] = y;
            end[1] = x;
            c = "z";
          }
          return c.charCodeAt(0) - "a".charCodeAt(0);
        })
    );
  const visited = map.map((row) => row.map(() => -1));

  while (queue.length) {
    const [y, x, d] = queue.shift()!;

    if (y === end[0] && x === end[1]) {
      return d;
    }

    if (visited[y][x] != -1 && visited[y][x] <= d) {
      continue;
    }
    visited[y][x] = d;

    const dy = [0, 0, 1, -1];
    const dx = [1, -1, 0, 0];
    for (let i = 0; i < 4; ++i) {
      const ny = y + dy[i];
      const nx = x + dx[i];

      if (ny < 0 || ny >= map.length || nx < 0 || nx >= map[ny].length) {
        continue;
      }
      if (map[ny][nx] <= map[y][x] + 1) {
        queue.push([ny, nx, d + 1]);
      }
    }
  }
  return -1;
}

console.log(solution(1));
console.log(solution(2));
