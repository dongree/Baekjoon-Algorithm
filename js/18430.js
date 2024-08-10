const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);

const arr = [];

const dy = [0, 1, 0, -1];
const dx = [1, 0, -1, 0];

const isVisited = Array(N)
  .fill()
  .map((e) => Array(M).fill(false));

for (let i = 1; i <= N; i++) {
  arr.push(inputs[i].split(' ').map(Number));
}
let result = 0;

dfs(0, 0);

console.log(result);
function dfs(n, score) {
  result = Math.max(result, score);
  for (let i = n; i < N * M; i++) {
    const y = Math.floor(i / M);
    const x = i % M;
    if (isVisited[y][x]) continue;

    for (let j = 0; j < 4; j++) {
      const ny1 = y + dy[j];
      const nx1 = x + dx[j];
      const ny2 = y + dy[(j + 1) % 4];
      const nx2 = x + dx[(j + 1) % 4];
      if (inRange(ny1, nx1) && inRange(ny2, nx2) && !isVisited[ny1][nx1] && !isVisited[ny2][nx2]) {
        isVisited[ny1][nx1] = true;
        isVisited[ny2][nx2] = true;
        isVisited[y][x] = true;
        dfs(i + 1, score + 2 * arr[y][x] + arr[ny1][nx1] + arr[ny2][nx2]);
        isVisited[y][x] = false;
        isVisited[ny2][nx2] = false;
        isVisited[ny1][nx1] = false;
      }
    }
  }
}

function inRange(y, x) {
  return 0 <= y && y < N && 0 <= x && x < M;
}
