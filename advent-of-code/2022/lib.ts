import { readAllSync } from "https://deno.land/std@0.167.0/streams/read_all.ts";

export function getInput(file: string | undefined) {
  if (!file) {
    return new TextDecoder().decode(
      readAllSync(Deno.stdin),
    ).trim();
  }
  return Deno.readTextFileSync(file).trim();
}
