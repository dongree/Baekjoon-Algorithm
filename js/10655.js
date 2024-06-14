const fs = require('fs');

const [[N], ...p] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const L = Array(N).fill(0);
const R = Array(N).fill(0);

for (let i = 1; i < N; i++) {
  L[i] = L[i - 1] + calcDist(p[i][0], p[i][1], p[i - 1][0], p[i - 1][1]);
}

for (let i = N - 2; i >= 0; i--) {
  R[i] = R[i + 1] + calcDist(p[i][0], p[i][1], p[i + 1][0], p[i + 1][1]);
}

let ans = Infinity;
for (let i = 1; i < N - 1; i++) {
  ans = Math.min(
    ans,
    L[i - 1] +
      R[i + 1] +
      calcDist(p[i - 1][0], p[i - 1][1], p[i + 1][0], p[i + 1][1])
  );
}

console.log(ans);

function calcDist(x1, y1, x2, y2) {
  return Math.abs(x1 - x2) + Math.abs(y1 - y2);
}
