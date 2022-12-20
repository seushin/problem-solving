import { assertEquals } from "../deps.ts";
import { getInput } from "../lib.ts";
import { part1, part2 } from "./day13.ts";

Deno.test("day13", async (t) => {
  const testInput = getInput(new URL("../test-input/day13", import.meta.url));

  await t.step("part1", () => {
    assertEquals(part1(testInput), 13);
  });

  await t.step("part2", () => {
    assertEquals(part2(testInput), 140);
  });

  const input = getInput(new URL("../input/day13", import.meta.url));
  console.log(part1(input));
  console.log(part2(input));
});
