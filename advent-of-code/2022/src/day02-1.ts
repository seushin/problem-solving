const filename = Deno.args[0];
const input = await Deno.readTextFile(filename);

// rock, paper scissors

function getMyScore(me: number, opponent: number) {
  let score = me;

  if (me === opponent) {
    score += 3;
  } else if (me === opponent + 1 || me + 2 === opponent) {
    score += 6;
  }
  return score;
}

const result = input
  .trim()
  .split("\n")
  .map((line) => {
    const [a, b] = line.trim().split(" ");
    const opponent = a.charCodeAt(0) - "A".charCodeAt(0) + 1;
    const me = b.charCodeAt(0) - "X".charCodeAt(0) + 1;

    return getMyScore(me, opponent);
  })
  .reduce((a, b) => a + b);

console.log(result);
