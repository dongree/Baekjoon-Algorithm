const fs = require('fs');

const [[N], ...points] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [sx, sy] = points[0];

let ans = 0;
for (let i = 2; i < N; i++) {
  ans += getTriangle(points[i], points[i - 1]);
}

console.log((Math.abs(ans) * 0.5).toFixed(1));

function getTriangle(a, b) {
  const [ax, ay] = a;
  const [bx, by] = b;

  return (ax - sx) * (by - sy) - (bx - sx) * (ay - sy);
}
