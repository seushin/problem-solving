import { assertEquals } from "../deps.ts";
import { getInput } from "../lib.ts";
import { solution } from "./day17.ts";

Deno.test("day17", async (t) => {
  const testInput = getInput(new URL("../test-input/day17", import.meta.url));

  await t.step("part1", () => {
    assertEquals(solution(testInput), 3068);
  });

  await t.step("part2", () => {
    assertEquals(solution(testInput, 1e12), 1514285714288);
  });

  const input = getInput(new URL("../input/day17", import.meta.url));
  console.log(solution(input));
  console.log(solution(input, 1e12));
});
