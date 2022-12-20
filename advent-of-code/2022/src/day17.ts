const rocks = [
  [["#", "#", "#", "#"]],
  [
    ["", "#", ""],
    ["#", "#", "#"],
    ["", "#", ""],
  ],
  [
    ["", "", "#"],
    ["", "", "#"],
    ["#", "#", "#"],
  ],
  [
    ["#"],
    ["#"],
    ["#"],
    ["#"],
  ],
  [
    ["#", "#"],
    ["#", "#"],
  ],
];

function getHeight(board: Set<string>) {
  return [...board]
    .map((s) => parseInt(s.split(",")[0]))
    .reduce((a, b) => Math.max(a, b), -1) + 1;
}

function isColliding(
  board: Set<string>,
  rock: string[][],
  pos: { y: number; x: number },
  width: number,
) {
  for (let y = 0; y < rock.length; ++y) {
    for (let x = 0; x < rock[y].length; ++x) {
      if (rock[y][x] !== "#") {
        continue;
      }

      const ny = pos.y - y;
      const nx = pos.x + x;
      if (nx < 0 || nx >= width || ny < 0 || board.has(`${ny},${nx}`)) {
        return true;
      }
    }
  }
  return false;
}

export function solution(
  jetPattern: string,
  rockCount = 2022,
  width = 7,
) {
  const board = new Set<string>();
  const cache = new Map<string, number[]>();
  jetPattern = jetPattern.trim();

  let plusHeight = 0;
  let nextJet = 0;
  let nextRock = 0;
  let currentRocks = 0;
  while (currentRocks < rockCount) {
    const rock = rocks[nextRock];
    let height = getHeight(board);
    let rockPos = { y: height + 3 + rock.length - 1, x: 2 };

    while (true) {
      const jet = jetPattern[nextJet] === ">" ? 1 : -1;
      nextJet = (nextJet + 1) % jetPattern.length;

      let nPos = { y: rockPos.y, x: rockPos.x + jet };
      if (!isColliding(board, rock, nPos, width)) {
        rockPos = nPos;
      }

      nPos = { y: rockPos.y - 1, x: rockPos.x };
      if (isColliding(board, rock, nPos, width)) {
        break;
      }
      rockPos = nPos;
    }

    for (let y = 0; y < rock.length; ++y) {
      for (let x = 0; x < rock[y].length; ++x) {
        if (rock[y][x] === "#") {
          board.add(`${rockPos.y - y},${rockPos.x + x}`);
        }
      }
    }

    height = getHeight(board);
    let key = `${nextJet},${nextRock}`;
    for (let y = height; y >= height - 10; y--) {
      let row = "";
      for (let x = 0; x < width; ++x) {
        row += board.has(`${y},${x}`) ? "#" : ".";
      }
      key += `,${row}`;
    }

    if (cache.has(key)) {
      const [cachedHeight, cachedRocks] = cache.get(key)!;
      const heightDiff = height - cachedHeight;
      const rockDiff = currentRocks - cachedRocks;
      const cycles = Math.floor((rockCount - cachedRocks) / rockDiff) - 1;

      plusHeight += cycles * heightDiff;
      currentRocks += cycles * rockDiff;
    } else {
      cache.set(key, [height, currentRocks]);
    }
    nextRock = (nextRock + 1) % rocks.length;
    currentRocks++;
  }
  return plusHeight + getHeight(board);
}
