import { getInput } from "../lib.ts";

function toCharCode(c: string): number {
  return c.charCodeAt(0) - 'a'.charCodeAt(0);
}

function solution(dist: number) {
  const input = getInput(Deno.args[0]).trim().split("");
  const buf = [...Array(26)].map(() => 0);

  input.slice(0, dist).map((c) => buf[toCharCode(c)]++);
  if (!buf.find((n) => n > 1)) {
    return dist;
  }
  for (let i = dist; i < input.length; ++i) {
    buf[toCharCode(input[i])]++;
    buf[toCharCode(input[i - dist])]--;
    if (!buf.find((n) => n > 1)) {
      return i + 1;
    }
  }
  return -1;
}

console.log(solution(4));
console.log(solution(14));
