const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const dy = [1, 0, -1, 0];
const dx = [0, 1, 0, -1];

const N = +inputs[0];
const arr = [];

let max = 0;

for (let i = 1; i <= N; i++) {
  const subArr = inputs[i].split(' ').map((e) => {
    if (e > max) max = e;
    return +e;
  });
  arr.push(subArr);
}

let answer = 1;

for (let k = 1; k < max; k++) {
  let cnt = 0;
  const isVisited = Array(N)
    .fill()
    .map(() => Array(N).fill(false));

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (arr[i][j] - k > 0 && !isVisited[i][j]) {
        isVisited[i][j] = true;
        dfs(i, j, k);
        cnt++;
      }
    }
  }
  answer = Math.max(answer, cnt);

  function dfs(y, x, sinkH) {
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (inRange(ny, nx) && arr[ny][nx] - sinkH > 0 && !isVisited[ny][nx]) {
        isVisited[ny][nx] = true;
        dfs(ny, nx, sinkH);
      }
    }
  }
}

console.log(answer);

function inRange(y, x) {
  return 0 <= y && y < N && 0 <= x && x < N;
}
