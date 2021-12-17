import { readFileSync } from 'fs';
import { fileURLToPath } from 'url';
import { dirname, join } from 'path';

const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);

const inputFile = readFileSync(join(__dirname, './input'));

let board = inputFile
  .toString()
  .trim(' ')
  .split('\n')
  .map((line) => {
    let ary = [];
    line.split('').map((c) => ary.push(parseInt(c)));
    return ary;
  });

// const printBoard = (board) => {
//   console.log();
//   board.forEach((line) => {
//     line.forEach((n) => {
//       process.stdout.write(String(n));
//     });
//     process.stdout.write('\n');
//   });
// };

const bfs = (sy, sx) => {
  let q = [];
  let visited = new Array(board.length).fill().map(() => {
    return new Array(board[0].length).fill(-1);
  });

  q.push([sy, sx]);
  visited[sy][sx] = 0;
  while (q.length > 0) {
    const [y, x] = q.shift();
    const direction = [
      [1, 0],
      [-1, 0],
      [0, 1],
      [0, -1],
    ];
    direction.forEach(([dy, dx]) => {
      const ny = y + dy;
      const nx = x + dx;

      if (ny < 0 || ny >= board.length || nx < 0 || nx >= board[0].length)
        return;
      const cost = visited[y][x] + board[ny][nx];
      if (visited[ny][nx] == -1 || visited[ny][nx] > cost) {
        q.push([ny, nx]);
        visited[ny][nx] = cost;
      }
    });
  }
  return visited.slice(-1)[0].slice(-1)[0];
};

console.log("answer :", bfs(0, 0));
