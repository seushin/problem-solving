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
  .map((line) =>
    line.split('').reduce((row, c) => {
      row.push(parseInt(c));
      return row;
    }, [])
  );

function bfs(board) {
  let q = [];
  let visited = new Array(board.length)
    .fill()
    .map(() => new Array(board[0].length).fill(-1));

  q.push([0, 0]);
  visited[0][0] = 0;
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
}

function extendBoard(board, size) {
  // horizontal
  board.map((row) => {
    const maxLen = row.length;
    for (let it = 1; it < size; ++it) {
      row.forEach((n, idx) => {
        if (idx >= maxLen) return;
        n += it;
        if (n > 9) n %= 9;
        row.push(n);
      });
    }
  });
  // vertical
  const maxLen = board.length;
  for (let it = 1; it < size; ++it) {
    board.forEach((row, idx) => {
      if (idx >= maxLen) return;
      const newElement = row.reduce((res, n) => {
        n += it;
        if (n > 9) n %= 9;
        res.push(n);
        return res;
      }, []);
      board.push(newElement);
    });
  }
  return board;
}

extendBoard(board, 5);
const minCost = bfs(board);

console.log('answer :', minCost);
