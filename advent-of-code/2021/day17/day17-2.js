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
  while (pos[0] <= targetX[1] && pos[1] >= targetY[0]) {
    if (isTrench(pos)) {
      return true;
    }

    pos[0] += velocity[0];
    pos[1] += velocity[1];
    velocity[0] -= velocity[0] == 0 ? 0 : velocity[0] > 0 ? 1 : -1;
    velocity[1]--;
  }
  return false;
};

const findVelocity = () => {
  let count = 0;

  for (let x = 1; x <= targetX[1]; ++x) {
    for (let y = targetY[0]; y < Math.abs(targetY[0]); ++y) {
      if (launchProbe([x, y])) count++;
    }
  }
  return count;
};

let result = findVelocity();
console.log('result :', result);
