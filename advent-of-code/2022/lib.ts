import { readAllSync } from "https://deno.land/std@0.167.0/streams/read_all.ts";

export function getInput(file: string | URL | undefined) {
  if (!file) {
    return new TextDecoder().decode(
      readAllSync(Deno.stdin),
    );
  }
  return Deno.readTextFileSync(file);
}
