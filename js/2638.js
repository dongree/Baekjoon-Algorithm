const fs = require('fs');

const [[N, M], ...arr] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const dy = [0, 1, 0, -1];
const dx = [1, 0, -1, 0];

let t = 0;

while (getCheese() !== 0) {
  const isVisited = Array(N)
    .fill()
    .map(() => Array(M).fill(false));

  bfs(0, 0);

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (arr[i][j] === 1 && willMelt(i, j)) {
        arr[i][j] = 0;
      }
    }
  }

  t++;

  function willMelt(y, x) {
    let cnt = 0;
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (inRange(ny, nx) && isVisited[ny][nx]) cnt++;
    }
    if (cnt >= 2) return true;
    return false;
  }

  function bfs(y, x) {
    const q = [[y, x]];
    let idx = 0;
    isVisited[y][x] = true;

    while (q.length !== idx) {
      const [cy, cx] = q[idx++];

      for (let i = 0; i < 4; i++) {
        const ny = cy + dy[i];
        const nx = cx + dx[i];

        if (inRange(ny, nx) && !isVisited[ny][nx] && arr[ny][nx] === 0) {
          isVisited[ny][nx] = true;
          q.push([ny, nx]);
        }
      }
    }
  }
}

console.log(t);

function getCheese() {
  let cnt = 0;
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (arr[i][j] === 1) {
        cnt++;
      }
    }
  }
  return cnt;
}

function inRange(y, x) {
  return 0 <= y && y < N && 0 <= x && x < M;
}
