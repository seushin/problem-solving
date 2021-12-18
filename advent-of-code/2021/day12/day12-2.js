import { readFileSync } from 'fs';

let inputFile = process.argv[2] || './input';
let input = readFileSync(inputFile, { encoding: 'utf-8' }).trim().split('\n');

function isSmall(v) {
  if (v.toUpperCase() == v) return false;
  return true;
}

function hasTwoSmall(visited) {
  for (let v of visited) {
    if (visited.filter(k => k == v).length > 1) return true;
  }
  return false;
}

function dfs(adj, visited, v) {
  if (v == 'end') {
    return 1;
  }
  let count = 0;

  for (let u of adj[v]) {
    if (isSmall(u)) {
      if (u == 'start' || ( visited.find((k) => k == u) && hasTwoSmall(visited))) continue;
      visited.push(u);
      count += dfs(adj, visited, u);
      visited.pop();
    } else {
      count += dfs(adj, visited, u);
    }
  }
  return count;
}

function solve(input) {
  let visited = [];
  let adj = {};

  for (let pair of input) {
    pair = pair.split('-');
    if (!adj[pair[0]]) adj[pair[0]] = [];
    adj[pair[0]].push(pair[1]);
    if (!adj[pair[1]]) adj[pair[1]] = [];
    adj[pair[1]].push(pair[0]);
  }

  visited.push('start');
  let count = dfs(adj, visited, 'start');
  return count;
}

console.log(solve(input));
