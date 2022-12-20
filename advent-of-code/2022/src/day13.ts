type Packet = number | Packet[];

function parsePacket(input: string): Packet[] {
  return JSON.parse(input);
}

function compare(lhs: Packet[], rhs: Packet[]): number {
  for (let i = 0; i < lhs.length || i < rhs.length; i++) {
    let l = lhs.at(i);
    let r = rhs.at(i);

    if (l === undefined) {
      return -1;
    } else if (r === undefined) {
      return 1;
    }

    if (Array.isArray(l) || Array.isArray(r)) {
      if (!Array.isArray(l)) {
        l = [l];
      }
      if (!Array.isArray(r)) {
        r = [r];
      }

      const res = compare(l, r);
      if (res !== 0) {
        return res;
      }
    } else {
      if (l !== r) {
        return l - r;
      }
    }
  }
  return 0;
}

export function part1(input: string) {
  return input
    .trim()
    .split("\n\n")
    .map((pair) => pair.split("\n").map((packet) => parsePacket(packet)))
    .map(([lhs, rhs]) => compare(lhs, rhs))
    .map((res, i) => res < 0 ? i + 1 : 0)
    .reduce((a, b) => a + b, 0);
}

export function part2(input: string) {
  const packets = input
    .trim()
    .split("\n\n")
    .map((pair) => pair.split("\n").map((packet) => parsePacket(packet)))
    .flat();

  const keys: Packet[][] = [
    [[2]],
    [[6]],
  ];
  packets.push(...keys);
  packets.sort(compare);
  return (packets.indexOf(keys[0]) + 1) * (packets.indexOf(keys[1]) + 1);
}
