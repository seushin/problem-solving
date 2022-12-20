import { assertEquals } from "../deps.ts";
import { getInput } from "../lib.ts";
import { part1, part2 } from "./day18.ts";

Deno.test("day18", async (t) => {
  const testInput = [
    `
1,1,1
2,1,1
`,
    getInput(new URL("../test-input/day18", import.meta.url)),
  ];

  await t.step("part1", () => {
    assertEquals(part1(testInput[0]), 10);
    assertEquals(part1(testInput[1]), 64);
  });

  await t.step("part2", () => {
    assertEquals(part2(testInput[1]), 58);
  });

  const input = getInput(new URL("../input/day18", import.meta.url));
  console.log(part1(input));
  console.log(part2(input));
});
