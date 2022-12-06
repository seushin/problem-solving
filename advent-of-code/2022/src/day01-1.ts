const filename = Deno.args[0];
const input = await Deno.readTextFile(filename);

const total = input
  .trim()
  .split("\n\n")
  .map((cal) =>
    cal.split("\n").reduce(
      (a, b) => a + Number(b),
      0,
    )
  );

const res = total
  .sort((a, b) => b - a)
  .slice(0, 1)
  .reduce((a, b) => a + b);

console.log(res);
