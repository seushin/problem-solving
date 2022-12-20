export function solution(part: number, input: string) {
  const sandStart = [500, 0];
  let maxHeight = 0;

  const rocks = new Set(
    input
      .trim()
      .split("\n")
      .map((path) =>
        path
          .split(" -> ")
          .map((pos) => pos.split(",").map((n) => parseInt(n, 10)))
      )
      .map((path) => {
        const rocks: string[] = [];

        let currentPos = path[0];
        maxHeight = Math.max(maxHeight, currentPos[1]);
        rocks.push(currentPos.join(","));
        for (let i = 0; i < path.length - 1; i++) {
          const nextPos = path[i + 1];
          const direction = nextPos
            .map((n, i) => n - currentPos[i])
            .map((n) => n === 0 ? 0 : n > 0 ? 1 : -1);

          while (currentPos[0] !== nextPos[0] || currentPos[1] !== nextPos[1]) {
            currentPos = currentPos.map((n, i) => n + direction[i]);
            maxHeight = Math.max(maxHeight, currentPos[1]);
            rocks.push(currentPos.join(","));
          }
        }
        return rocks;
      })
      .flat(),
  );
  maxHeight += 2;

  const sands = new Set<string>();
  let loop = true;
  while (loop) {
    let current = sandStart;

    while (true) {
      const below = [current[0], current[1] + 1];
      const left = [current[0] - 1, current[1] + 1];
      const right = [current[0] + 1, current[1] + 1];

      if (below[1] >= maxHeight) {
        if (part === 1) {
          loop = false;
        }
        if (part === 2) {
          rocks.add(current.join(","));
          sands.add(current.join(","));
        }
        break;
      }

      if (!rocks.has(below.join(","))) {
        current = below;
      } else if (!rocks.has(left.join(","))) {
        current = left;
      } else if (!rocks.has(right.join(","))) {
        current = right;
      } else {
        rocks.add(current.join(","));
        sands.add(current.join(","));

        if (current[1] === sandStart[1]) {
          loop = false;
        }
        break;
      }
    }
  }
  return sands.size;
}
