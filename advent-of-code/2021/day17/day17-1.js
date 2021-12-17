import { readFileSync } from 'fs';
import { fileURLToPath } from 'url';
import { dirname, join } from 'path';

const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);

let input = readFileSync(join(__dirname, './input'), {
  encoding: 'utf-8',
}).trim();

input = input.slice('target area: '.length).split(', ');
let targetX = input[0]
  .slice(2)
  .split('..')
  .map((n) => parseInt(n));
let targetY = input[1]
  .slice(2)
  .split('..')
  .map((n) => parseInt(n));

const isTrench = (pos) => {
  let checkX = targetX[0] <= pos[0] && pos[0] <= targetX[1];
  let checkY = targetY[0] <= pos[1] && pos[1] <= targetY[1];

  return checkX && checkY;
};

const launchProbe = (velocity = [1, 1]) => {
  let pos = [0, 0];
  let maxY = Number.MIN_VALUE;
  while (pos[0] <= targetX[1] && pos[1] >= targetY[0]) {
    if (isTrench(pos)) {
      return maxY;
    }

    pos[0] += velocity[0];
    pos[1] += velocity[1];
    velocity[0] -= velocity[0] == 0 ? 0 : velocity[0] > 0 ? 1 : -1;
    velocity[1]--;
    maxY = Math.max(maxY, pos[1]);
  }
  return false;
};

const findMaxY = () => {
  let res = [];

  for (let x = 1; x <= targetX[1]; ++x) {
    for (let y = 0; y < Math.abs(targetY[0]); ++y) {
      let hight = launchProbe([x, y]);
      if (hight) res.push(hight);
    }
  }
  return res;
};

let result = Math.max(...findMaxY());
console.log('result :', result);
