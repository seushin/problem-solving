function* generateAdjacentDroplet(x: number, y: number, z: number) {
  for (let dx = -1; dx <= 1; ++dx) {
    for (let dy = -1; dy <= 1; ++dy) {
      for (let dz = -1; dz <= 1; ++dz) {
        const dist = Math.abs(dx) + Math.abs(dy) + Math.abs(dz);
        if (dist === 1) {
          yield [x + dx, y + dy, z + dz];
        }
      }
    }
  }
}

export function part1(input: string) {
  const droplets = new Set(input.trim().split("\n"));

  let surfaces = 0;
  for (const droplet of droplets) {
    for (
      const [x, y, z] of generateAdjacentDroplet(
        ...droplet.split(",").map(Number) as [number, number, number],
      )
    ) {
      if (!droplets.has(`${x},${y},${z}`)) {
        surfaces++;
      }
    }
  }
  return surfaces;
}

export function part2(input: string) {
  const droplets = new Set(input.trim().split("\n"));

  const min = [Infinity, Infinity, Infinity];
  const max = [-Infinity, -Infinity, -Infinity];
  droplets.forEach((droplet) => {
    droplet
      .split(",")
      .map((n) => parseInt(n, 10))
      .map((n, i) => {
        min[i] = Math.min(min[i], n);
        max[i] = Math.max(max[i], n);
      });
  });

  let surfaces = 0;
  const queue = [min.map((n) => n - 1)];
  const visited = new Set<string>();

  while (queue.length) {
    const [x, y, z] = queue.shift()!;
    const key = `${x},${y},${z}`;

    if (visited.has(key)) {
      continue;
    }
    visited.add(key);

    for (const droplet of generateAdjacentDroplet(x, y, z)) {
      if (droplet.some((n, i) => n < min[i] - 1 || n > max[i] + 1)) {
        continue;
      }

      const nkey = droplet.join(",");
      if (droplets.has(nkey)) {
        surfaces++;
      } else if (!visited.has(nkey)) {
        queue.push(droplet);
      }
    }
  }
  return surfaces;
}
