import { readFileSync } from 'fs';

const file = process.argv[2] || './input';
const data = readFileSync(file, { encoding: 'utf-8' }).trim().split('\n\n');

const algo = data[0];
let image = data[1].split('\n').map((row) => row.split(''));

const print = (board) => {
  board.map((row) => {
    row.map((c) => process.stdout.write(c));
    process.stdout.write('\n');
  });
  process.stdout.write('\n');
};

const expand = (board, size, fill = '#') => {
  let newBoard = new Array(board.length + size)
    .fill()
    .map(() => new Array(board[0].length + size).fill(fill));

  size = Math.ceil(size / 2);
  for (let y = 0; y < board.length; ++y) {
    for (let x = 0; x < board[y].length; ++x) {
      newBoard[y + size][x + size] = board[y][x];
    }
  }
  return newBoard;
};

const convert = (board, y, x) => {
  let res = 0;
  for (let ny = y - 1; ny <= y + 1; ++ny) {
    for (let nx = x - 1; nx <= x + 1; ++nx) {
      res *= 2;
      if (board[ny][nx] === '#') res += 1;
    }
  }
  return res;
};

const enhancement = (board) => {
  let newBoard = expand(board, 2, board[0][0]);
  let tmp = newBoard.map((row) => row.slice());
  for (let y = 0; y < newBoard.length; ++y) {
    for (let x = 0; x < newBoard[y].length; ++x) {
      if (
        y === 0 ||
        y === newBoard.length - 1 ||
        x === 0 ||
        x === newBoard[y].length - 1
      )
        newBoard[y][x] = algo[tmp[y][x] === '#' ? 511 : 0];
      else newBoard[y][x] = algo[convert(tmp, y, x)];
    }
  }
  return newBoard;
};

const repeat = (board, times) => {
  board = expand(board, 2, '.');
  for (let i = 0; i < times; ++i) {
    board = enhancement(board);
  }

  let count = 0;
  board.map((row) =>
    row.map((c) => {
      if (c === '#') count++;
    })
  );
  return count;
};

let count;
count = repeat(image, 2);
console.log(count);
count = repeat(image, 50);
console.log(count);
