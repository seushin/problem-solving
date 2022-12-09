import { getInput } from "../lib.ts";

type Direction = "R" | "L" | "U" | "D";

const direction = {
  "R": [0, 1],
  "L": [0, -1],
  "U": [1, 0],
  "D": [-1, 0],
};

function isTooFar(head: number[], tail: number[]) {
  const dist = head
    .map((p, i) => p - tail[i])
    .map(Math.abs);

  if (dist.find((d) => d > 1)) {
    return true;
  }
  return false;
}

function moveTail(head: number[], tail: number[]) {
  const dist = head.map((p, i) => p - tail[i]);
  const step = dist.map((d) => d > 0 ? 1 : -1);

  if (dist[0] === 0) {
    return [tail[0], tail[1] + step[1]];
  } else if (dist[1] === 0) {
    return [tail[0] + step[0], tail[1]];
  } else {
    return [tail[0] + step[0], tail[1] + step[1]];
  }
}

function solution(len: number) {
  const knot: number[][] = [...Array(len)].map(() => [0, 0]);
  const visited = new Set<string>(["0,0"]);

  getInput(Deno.args[0])
    .trim()
    .split("\n")
    .map((line) => {
      const [d, s] = line.split(" ");
      const dir = direction[d as Direction];
      const step = parseInt(s, 10);

      for (let it = 0; it < step; ++it) {
        knot[0] = knot[0].map((p, id) => p + dir[id]);

        for (let i = 1; i < knot.length; ++i) {
          if (isTooFar(knot[i - 1], knot[i])) {
            knot[i] = moveTail(knot[i - 1], knot[i]);
          }
        }

        visited.add(knot[len - 1].join(","));
      }
    });

  return visited.size;
}

console.log(solution(2));
console.log(solution(10));
