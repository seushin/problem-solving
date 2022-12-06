const filename = Deno.args[0];
const input = await Deno.readTextFile(filename);

const res = input.trim()
  .split("\n")
  .map((line) => {
    const first = line.slice(0, line.length / 2);
    const second = line.slice(line.length / 2);
    const compartment = new Set<string>();

    for (const char of first) {
      compartment.add(char);
    }
    for (const char of second) {
      if (compartment.has(char)) {
        return char;
      }
    }
    return "0";
  })
  .reduce((a, b) => {
    let ascii = b.charCodeAt(0);

    if (ascii >= 'a'.charCodeAt(0) && ascii <= 'z'.charCodeAt(0)) {
      ascii -= 'a'.charCodeAt(0) - 1;
    } else {
      ascii += 26 - 'A'.charCodeAt(0) + 1;
    }
    return a + ascii;
  }, 0);

console.log(res);
