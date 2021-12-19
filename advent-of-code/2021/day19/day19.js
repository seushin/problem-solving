import { readFileSync } from 'fs';

const file = process.argv[2] || './input';
const data = readFileSync(file, { encoding: 'utf-8' });
const scanners = data
  .trim()
  .split('\n\n')
  .map((scanner) =>
    scanner
      .split('\n')
      .slice(1)
      .map((pos) => pos.split(',').map(Number))
  );

const rotate = [
  ([x, y, z]) => [x, y, z],
  ([x, y, z]) => [y, z, x],
  ([x, y, z]) => [z, x, y],
  ([x, y, z]) => [-x, z, y],
  ([x, y, z]) => [z, y, -x],
  ([x, y, z]) => [y, -x, z],
  ([x, y, z]) => [x, z, -y],
  ([x, y, z]) => [z, -y, x],
  ([x, y, z]) => [-y, x, z],
  ([x, y, z]) => [x, -z, y],
  ([x, y, z]) => [-z, y, x],
  ([x, y, z]) => [y, x, -z],
  ([x, y, z]) => [-x, -y, z],
  ([x, y, z]) => [-y, z, -x],
  ([x, y, z]) => [z, -x, -y],
  ([x, y, z]) => [-x, y, -z],
  ([x, y, z]) => [y, -z, -x],
  ([x, y, z]) => [-z, -x, y],
  ([x, y, z]) => [x, -y, -z],
  ([x, y, z]) => [-y, -z, x],
  ([x, y, z]) => [-z, x, -y],
  ([x, y, z]) => [-x, -z, -y],
  ([x, y, z]) => [-z, -y, -x],
  ([x, y, z]) => [-y, -x, -z],
];

const sub = (a, b) => a.map((n, i) => n - b[i]);
const sum = (add) => (pos) => pos.map((n, i) => n + add[i]);

const sameBeacons = (set, ary) =>
  ary.filter((pos) => set.has(JSON.stringify(pos)));

const getRelativePos = (scanner) => {
  for (let i = 0; i < 24; ++i) {
    let rotated = scanner.map(rotate[i]);
    for (let p0 of beacons) {
      for (let p1 of rotated) {
        let diff = sub(JSON.parse(p0), p1);
        let align = rotated.map(sum(diff));
        let f = sameBeacons(beacons, align);
        if (f.length >= 12) {
          return [diff, align];
        }
      }
    }
  }
  return undefined;
};

let scannerPos = [[0, 0, 0]];
let beacons = new Set(scanners[0].map(JSON.stringify));
const findBeacons = () => {
  let rest = scanners.slice(1);
  while (rest.length) {
    for (let scanner of rest) {
      let res = getRelativePos(scanner);
      if (res) {
        let [diff, aligned] = res;
        aligned.forEach((pos) => beacons.add(JSON.stringify(pos)));
        scannerPos.push(diff);
        rest = rest.filter((s) => s !== scanner);
        console.log(beacons.size, rest.length);
        break;
      }
    }
  }
  return beacons.size;
};

console.log('beacons :', findBeacons());

const dists = `
[
  [ 0, 0, 0 ],            [ 0, -31, 1119 ],
  [ -1321, 2, -46 ],      [ -49, -24, -1280 ],
  [ 37, -80, -2444 ],     [ -86, 1149, -2358 ],
  [ 1209, 1115, -2505 ],  [ 1130, 1142, -1272 ],
  [ -31, 1180, -3732 ],   [ -1186, 1025, -3561 ],
  [ 1184, 2246, -1175 ],  [ 2385, 2256, -1269 ],
  [ 3541, 2416, -1333 ],  [ -1255, 1192, -127 ],
  [ 1261, -21, -2424 ],   [ -1162, 1081, -1316 ],
  [ -1314, 2341, -1255 ], [ -126, 2258, -2504 ],
  [ 27, 3540, -2514 ],    [ 1121, 2312, -3580 ],
  [ 1245, 2227, -4750 ],  [ 1216, 3439, -4790 ],
  [ 2404, 2318, -3662 ],  [ 3577, 2304, -3694 ],
  [ 3660, 3611, -3682 ],  [ 1173, 1062, -4865 ],
  [ 1160, 1099, -6084 ],  [ -2357, 1058, -1236 ],
  [ 1254, 2329, 40 ],     [ 40, 2228, -1279 ],
  [ 1238, -178, -78 ],    [ 1211, 2274, -5952 ],
  [ 3615, 2401, -4791 ],  [ -1178, 2303, -2387 ],
  [ -125, 2374, -5970 ],  [ 69, 2375, -7236 ],
  [ 65, 1168, -1208 ],    [ 1165, 2344, -2394 ],
  [ 1116, 3482, -5996 ]
]
`;

// scannerPos = JSON.parse(dists);
let manhattanDist = 0;
for (let i = 0; i < scannerPos.length; ++i) {
  for (let j = i + 1; j < scannerPos.length; ++j) {
    manhattanDist = Math.max(
      manhattanDist,
      sub(scannerPos[i], scannerPos[j]).map(Math.abs).reduce((a, b) => a + b),
      sub(scannerPos[j], scannerPos[i]).map(Math.abs).reduce((a, b) => a + b)
    );
  }
}

console.log('Manhattan Dist :', manhattanDist);
