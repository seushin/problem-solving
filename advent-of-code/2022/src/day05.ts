import { getInput } from "../lib.ts";

function parseCrates(input: string) {
  const lines = input.split("\n").reverse();
  const crates: string[][] = [...Array(10)].map(() => []);

  for (let i = 1; i < lines.length; ++i) {
    const line = lines[i];
    for (let j = 1; j < line.length; j += 4) {
      if (line[j] != " ") {
        const idx = parseInt(lines[0][j], 10);
        crates[idx].push(line[j]);
      }
    }
  }

  return crates;
}

function parseProcedure(input: string) {
  const [_move, count, _from, from, _to, to] = input.split(" ").map((n) =>
    parseInt(n, 10)
  );

  return [count, from, to];
}

type Rearrangement = (
  crates: string[][],
  count: number,
  from: number,
  to: number,
) => void;

function solution(f: Rearrangement) {
  const [cratePart, procedurePart] = getInput(Deno.args[0])
    .split("\n\n");
  const crates = parseCrates(cratePart);

  procedurePart
    .trim()
    .split("\n")
    .map((procedure) => {
      const [count, from, to] = parseProcedure(procedure);
      f(crates, count, from, to);
    });
  return crates.map((crate) => crate.at(-1)).join("");
}

const part1: Rearrangement = (crates, count, from, to) => {
  for (let i = 0; i < count; ++i) {
    const target = crates[from].pop();
    if (target) {
      crates[to].push(target);
    }
  }
};

const part2: Rearrangement = (crates, count, from, to) => {
  const tmp: string[] = [];
  for (let i = 0; i < count; ++i) {
    const target = crates[from].pop();
    if (target) {
      tmp.push(target);
    }
  }
  tmp.reverse().map((c) => crates[to].push(c));
};

console.log(solution(part1));
console.log(solution(part2));
