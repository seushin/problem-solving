function parseLocations(input: string) {
  return input
    .trim()
    .split("\n")
    .map((line) => {
      const [sx, sy, bx, by] = line
        .match(/(-?\d+)/g)!
        .map((n) => parseInt(n, 10));
      const range = Math.abs(sx - bx) + Math.abs(sy - by);

      return { sx, sy, bx, by, range };
    });
}

export function part1(input: string, row: number) {
  const locations = parseLocations(input);

  const clearZone = new Set<number>();
  locations.map((loc) => {
    loc.range -= Math.abs(row - loc.sy);
    if (loc.range <= 0) {
      return;
    }
    for (let i = -loc.range; i <= loc.range; ++i) {
      clearZone.add(loc.sx + i);
    }
  });
  locations.map((loc) => {
    if (loc.by === row && clearZone.has(loc.bx)) {
      clearZone.delete(loc.bx);
    }
  });
  return clearZone.size;
}

export function part2(input: string, range: number) {
  const n = 4000000;
  const locations = parseLocations(input);

  const dx = [1, 1, -1, -1];
  const dy = [1, -1, 1, -1];
  for (const loc of locations) {
    for (let i = 0; i < 4; ++i) {
      for (let nx = 0; nx <= loc.range + 1; ++nx) {
        const ny = loc.range + 1 - nx;
        const x = loc.sx + dx[i] * nx;
        const y = loc.sy + dy[i] * ny;

        if (x < 0 || y < 0 || x > range || y > range) {
          continue;
        }
        if (
          locations.every((l) =>
            l.range < Math.abs(l.sx - x) + Math.abs(l.sy - y)
          )
        ) {
          return x * n + y;
        }
      }
    }
  }
  return -1;
}
