import { assertEquals } from "../deps.ts";
import { getInput } from "../lib.ts";
import { part1, part2 } from "./day15.ts";

Deno.test("day15", async (t) => {
  const testInput = getInput(new URL("../test-input/day15", import.meta.url));

  await t.step("part1", () => {
    assertEquals(part1(testInput, 10), 26);
  });

  await t.step("part2", () => {
    assertEquals(part2(testInput, 20), 56000011);
  });

  const input = getInput(new URL("../input/day15", import.meta.url));
  console.log(part1(input, 2000000));
  console.log(part2(input, 4000000));
});
