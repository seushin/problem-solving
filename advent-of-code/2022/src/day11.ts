import { getInput } from "../lib.ts";

interface Monkey {
  items: number[];
  op(old: number): number;
  test(item: number): number;
  inspects: number;
  div: number;
}

function parseOp(operator: string, rhs: string) {
  return function operation(old: number) {
    const n = rhs === "old" ? old : parseInt(rhs, 10);
    return operator === "*" ? n * old : n + old;
  };
}

function parseTest(div: number, t: number, f: number) {
  return function test(item: number) {
    return item % div === 0 ? t : f;
  };
}

function parseMonkey(input: string) {
  return input
    .split("\n\n")
    .map((desc) => {
      const lines = desc.split("\n").map((l) => l.trim());

      const items: number[] = lines[1]
        .slice("Starting items: ".length)
        .split(", ")
        .map((n) => parseInt(n, 10));

      const opParams = lines[2]
        .slice("Operation: new = old ".length)
        .split(" ");

      const testParams = lines
        .slice(3)
        .map((line) => line.split(" ").at(-1) ?? "")
        .map((n) => parseInt(n, 10));

      return {
        items,
        op: parseOp(opParams[0], opParams[1]),
        test: parseTest(testParams[0], testParams[1], testParams[2]),
        inspects: 0,
        div: testParams[0],
      } as Monkey;
    });
}

function solution(part: number, round: number) {
  const monkeys = parseMonkey(getInput(Deno.args[0]));
  const div = monkeys.map((monkey) => monkey.div).reduce((a, b) => a * b);

  for (let iter = 0; iter < round; ++iter) {
    monkeys.map((monkey) => {
      monkey.items.map((item) => {
        let worryLevel = monkey.op(item);

        if (part === 1) {
          worryLevel = Math.floor(worryLevel / 3);
        } else if (part === 2) {
          worryLevel %= div;
        }

        const thrownTo = monkey.test(worryLevel);
        monkeys[thrownTo].items.push(worryLevel);
        monkey.inspects++;
      });
      monkey.items = [];
    });
  }

  return monkeys
    .map((monkey) => monkey.inspects)
    .sort((a, b) => b - a)
    .slice(0, 2)
    .reduce((a, b) => a * b);
}

console.log(solution(1, 20));
console.log(solution(2, 10000));
