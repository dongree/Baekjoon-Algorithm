const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = [];

for (let i = 1; i <= N; i++) {
  arr.push(inputs[i].split(' ').map(Number));
}

const dp = Array(N)
  .fill()
  .map(() => Array(N).fill(0n));

dp[0][0] = 1n;

for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    if (arr[i][j] === 0) continue;

    if (dp[i][j] !== 0n) {
      const ny1 = i + arr[i][j];
      const nx1 = j;

      const ny2 = i;
      const nx2 = j + arr[i][j];

      if (0 <= ny1 && ny1 < N) dp[ny1][nx1] += dp[i][j];
      if (0 <= nx2 && nx2 < N) dp[ny2][nx2] += dp[i][j];
    }
  }
}

console.log(dp[N - 1][N - 1].toString());
