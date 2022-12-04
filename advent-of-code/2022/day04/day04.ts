import { getInput } from "../lib.ts";

const solution = (f: (a: number[], b: number[]) => number) =>
  getInput(Deno.args[0])
    .split("\n")
    .map((line) =>
      line
        .split(",")
        .map((pair) =>
          pair
            .split("-")
            .map((n) => parseInt(n))
        )
    )
    .map((pairs) =>
      f(pairs[0], pairs[1]) ||
      f(pairs[1], pairs[0])
    ).reduce((a, b) => a + b);

function isFullyOverlap(a: number[], b: number[]): number {
  if (a[0] <= b[0] && a[1] >= b[1]) {
    return 1;
  }
  return 0;
}

function isOverlap(a: number[], b: number[]): number {
  if (a[0] <= b[0] && a[1] >= b[0]) {
    return 1;
  } else if (a[0] <= b[1] && a[1] >= b[1]) {
    return 1;
  }
  return 0;
}

console.log(solution(isFullyOverlap));
console.log(solution(isOverlap));
