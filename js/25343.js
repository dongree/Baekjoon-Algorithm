const fs = require('fs');

const [[N], ...arr] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const dp = Array(N)
  .fill()
  .map(() => Array(N).fill(0));

dp[0][0] = 1;

for (let i = 0; i < N; i++) {
  dp[0][i] = 1;
  dp[i][0] = 1;
  for (let j = 0; j < i; j++) {
    if (arr[0][j] < arr[0][i]) dp[0][i] = Math.max(dp[0][i], dp[0][j] + 1);
  }
  for (let j = 0; j < i; j++) {
    if (arr[j][0] < arr[j][0]) dp[i][0] = Math.max(dp[i][0], dp[j][0] + 1);
  }
}

for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    dp[i][j] = 1;
    for (let a = 0; a <= i; a++) {
      for (let b = 0; b <= j; b++) {
        if (arr[a][b] < arr[i][j]) dp[i][j] = Math.max(dp[i][j], dp[a][b] + 1);
      }
    }
  }
}

let ans = 0;

for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    ans = Math.max(ans, dp[i][j]);
  }
}

console.log(ans);
