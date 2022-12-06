const filename = Deno.args[0];
const input = await Deno.readTextFile(filename);

// rock, paper scissors

function getMyScore(me: number, opponent: number) {
  let score = me * 3 + 1;

  if (me === 0) {
    score += (opponent + 3 - 1) % 3;
  } else if (me === 1) {
    score += opponent;
  } else if (me === 2) {
    score += (opponent + 1) % 3;
  }
  console.log(score)
  return score;
}

const result = input
  .trim()
  .split("\n")
  .map((line) => {
    const [a, b] = line.trim().split(" ");
    const opponent = a.charCodeAt(0) - "A".charCodeAt(0);
    const me = b.charCodeAt(0) - "X".charCodeAt(0);

    return getMyScore(me, opponent);
  })
  .reduce((a, b) => a + b);

console.log(result);
