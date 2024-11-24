const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];

const [M, N] = getLine();
const board = [];

const dy = [0, 1, 0, -1];
const dx = [1, 0, -1, 0];

const memo = Array(M)
  .fill()
  .map(() => Array(N).fill(-1));

for (let i = 0; i < M; i++) {
  const subArr = getLine();
  board.push(subArr);
}

console.log(dfs(0, 0));
console.log(memo);

function dfs(y, x) {
  if (y === M - 1 && x === N - 1) {
    return 1;
  }

  if (memo[y][x] !== -1) return memo[y][x];

  memo[y][x] = 0;
  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    if (inRange(ny, nx) && board[y][x] > board[ny][nx]) {
      memo[y][x] += dfs(ny, nx);
    }
  }

  return memo[y][x];
}

function inRange(y, x) {
  return 0 <= y && y < M && 0 <= x && x < N;
}
