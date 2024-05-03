const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];

const [n, m, r] = getLine();
const itemN = [0, ...getLine()];

const dist = Array(n + 1)
  .fill()
  .map((_, i) =>
    Array(n + 1)
      .fill()
      .map((e, j) => {
        if (i === j) return 0;
        else return Infinity;
      })
  );

for (let i = 0; i < r; i++) {
  const [a, b, l] = getLine();
  dist[a][b] = l;
  dist[b][a] = l;
}

for (let k = 1; k <= n; k++) {
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= n; j++) {
      dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }
}

let ans = 0;
for (let i = 1; i <= n; i++) {
  let v = 0;
  for (let j = 1; j <= n; j++) {
    if (dist[i][j] <= m) v += itemN[j];
  }
  if (v > ans) ans = v;
}

console.log(ans);
