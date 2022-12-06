const filename = Deno.args[0];
const input = await Deno.readTextFile(filename);

let compartment: Set<string>;

const lines = input.trim()
  .split("\n")

let sum = 0;

for (let i = 0; i < lines.length; i += 3) {
    const first = new Set<string>();
    const second = new Set<string>();

    for (const char of lines[i]) {
      first.add(char);
    }

    for (const char of lines[i + 1]) {
      if (first.has(char)) {
        second.add(char);
      }
    }

    let res = "";
    for (const char of lines[i + 2]) {
      if (second.has(char)) {
        res = char;
        break;
      }
    }
    let ascii = res.charCodeAt(0);

    if (ascii >= "a".charCodeAt(0) && ascii <= "z".charCodeAt(0)) {
      ascii -= "a".charCodeAt(0) - 1;
    } else {
      ascii += 26 - "A".charCodeAt(0) + 1;
    }
    sum += ascii;
}

console.log(sum);
