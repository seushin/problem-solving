import { readFileSync } from 'fs';

const file = process.argv[2] || './input';
let input = readFileSync(file, { encoding: 'utf-8' })
  .trim()
  .split('\n')
  .map(JSON.parse);

function magnitude(pair) {
  if (!Array.isArray(pair)) return pair;
  let res = magnitude(pair[0]) * 3 + magnitude(pair[1]) * 2;
  return res;
}

function add(a, b) {
  a = JSON.parse(JSON.stringify(a));
  b = JSON.parse(JSON.stringify(b));
  return reduce([a, b]);
}

function reduce(pair) {
  while (explode(pair) || split(pair));
  return pair;
}

function explode(pair, depth = 0, parent = null) {
  if (!Array.isArray(pair)) return;

  const addValue = (pair, lr, value) => {
    if (Array.isArray(pair[lr])) addValue(pair[lr], lr, value);
    else pair[lr] += value;
  };
  // if depth > 5, += operator will be broken
  if (depth < 4) {
    let p;
    if (Array.isArray(pair[0]) && (p = explode(pair[0], depth + 1, pair))) {
      if (p[1]) {
        if (!Array.isArray(pair[1])) pair[1] += p[1];
        else addValue(pair[1], 0, p[1]);
        return [p[0], undefined];
      }
      return p;
    }
    if (Array.isArray(pair[1]) && (p = explode(pair[1], depth + 1, pair))) {
      if (p[0]) {
        if (!Array.isArray(pair[0])) pair[0] += p[0];
        else addValue(pair[0], 1, p[0]);
        return [undefined, p[1]];
      }
      return p;
    }
  } else {
    let whoami = parent[0] === pair ? 0 : 1;
    parent[whoami] = 0;
    return pair;
  }
  return;
}

function split(pair) {
  if (!Array.isArray(pair)) return [Math.floor(pair / 2), Math.ceil(pair / 2)];
  let res;
  if (Array.isArray(pair[0]) && (res = split(pair[0]))) return res;
  else if (pair[0] >= 10) return (pair[0] = split(pair[0]));
  else if (Array.isArray(pair[1]) && (res = split(pair[1]))) return res;
  else if (pair[1] >= 10) return (pair[1] = split(pair[1]));
  return;
}

const sum = input.slice().reduce(add);
const res = magnitude(sum);

console.log(JSON.stringify(sum), res);
