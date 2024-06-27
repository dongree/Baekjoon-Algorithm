const fs = require('fs');

const [N, M] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

const isVisited = Array(N)
  .fill()
  .map(() => Array(M).fill(false));
let cnt = 0;

dfs(0);

console.log(cnt);

function dfs(n) {
  if (n == N * M) {
    cnt++;
    return;
  }

  const y = Math.floor(n / M);
  const x = n % M;

  if (!check(y, x)) {
    isVisited[y][x] = true;
    dfs(n + 1);
    isVisited[y][x] = false;
  }
  dfs(n + 1);
}

function check(y, x) {
  return (
    0 < y &&
    0 < x &&
    isVisited[y - 1][x - 1] &&
    isVisited[y - 1][x] &&
    isVisited[y][x - 1]
  );
}
