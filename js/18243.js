const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [N, K] = inputs[0];

const dist = Array(N + 1)
  .fill()
  .map((_, i) =>
    Array(N + 1)
      .fill()
      .map((_, j) => {
        if (i === j) return 0;
        return Infinity;
      })
  );

for (let i = 1; i <= K; i++) {
  const [a, b] = inputs[i];
  dist[a][b] = 1;
  dist[b][a] = 1;
}

for (let k = 1; k <= N; k++) {
  for (let i = 1; i <= N; i++) {
    for (let j = 1; j <= N; j++) {
      dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }
}

let flag = true;

a: for (let i = 1; i <= N; i++) {
  for (let j = 1; j <= N; j++) {
    if (dist[i][j] > 6) {
      flag = false;
      break a;
    }
  }
}

if (flag) console.log('Small World!');
else console.log('Big World!');
