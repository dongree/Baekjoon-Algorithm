const fs = require('fs');

const [N, K] = fs.readFileSync('example.txt').toString().trim().split(' ').map(Number);

const dp = Array(N + 1)
  .fill()
  .map(() => Array(N + 1).fill(0));

for (let i = 1; i <= N; i++) {
  dp[i][0] = 1;
  dp[i][i] = 1;
}

// nCk = n-1Ck-1 + n-1Ck
for (let i = 2; i <= N; i++) {
  for (let j = 1; j <= i; j++) {
    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
  }
}

console.log(dp[N][K]);
