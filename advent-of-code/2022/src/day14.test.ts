import { assertEquals } from "../deps.ts";
import { getInput } from "../lib.ts";
import { solution } from "./day14.ts";

Deno.test("day14", async (t) => {
  const testInput = getInput(new URL("../test-input/day14", import.meta.url));

  await t.step("part1", () => {
    assertEquals(solution(1, testInput), 24);
  });

  await t.step("part2", () => {
    assertEquals(solution(2, testInput), 93);
  });

  const input = getInput(new URL("../input/day14", import.meta.url));
  console.log(solution(1, input));
  console.log(solution(2, input));
});
