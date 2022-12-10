import { getInput } from "../lib.ts";

function part1() {
  let sum = 0;
  let register = 1;
  let clock = 0;
  const signal = [20, 60, 100, 140, 180, 220];

  getInput(Deno.args[0])
    .trim()
    .split("\n")
    .map((line) => {
      if (line === "noop") {
        return [1, 0];
      }
      return [2, parseInt(line.split(" ")[1], 10)];
    })
    .map((inst) => {
      clock += inst[0];
      if (clock === signal[0] || clock - 1 === signal[0]) {
        sum += signal[0] * register;
        signal.shift();
      }
      register += inst[1];
    });
  return sum;
}

function part2() {
  const image = [...Array(6)].map(() => [...Array(40)].map(() => ""));
  let spritePos = 1;
  let clock = 0;

  getInput(Deno.args[0])
    .trim()
    .split("\n")
    .map((line) => {
      if (line === "noop") {
        return [1, 0];
      }
      return [2, parseInt(line.split(" ")[1], 10)];
    })
    .map((inst) => {
      while (inst[0]--) {
        const drawPos = clock % 40;
        let pixel = ".";

        if (drawPos >= spritePos - 1 && drawPos <= spritePos + 1) {
          pixel = "#";
        }
        image[Math.floor(clock / 40)][drawPos] = pixel;
        clock++;
      }
      spritePos += inst[1];
    });
  return image
    .map((line) => line.join(""))
    .join("\n");
}

console.log(part1());
console.log(part2());
