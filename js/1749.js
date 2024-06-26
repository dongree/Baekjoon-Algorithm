const fs = require('fs');

const [[N, M], ...arr] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const ps = Array(N + 1)
  .fill()
  .map(() => Array(M + 1).fill(0));

for (let i = 1; i <= N; i++) {
  for (let j = 1; j <= M; j++) {
    ps[i][j] =
      arr[i - 1][j - 1] + ps[i][j - 1] + ps[i - 1][j] - ps[i - 1][j - 1];
  }
}

let ans = -Infinity;

for (let y1 = 1; y1 <= N; y1++) {
  for (let x1 = 1; x1 <= M; x1++) {
    for (let y2 = y1; y2 <= N; y2++) {
      for (let x2 = x1; x2 <= M; x2++) {
        const k =
          ps[y2][x2] - ps[y2][x1 - 1] - ps[y1 - 1][x2] + ps[y1 - 1][x1 - 1];
        ans = Math.max(ans, k);
      }
    }
  }
}

console.log(ans);
