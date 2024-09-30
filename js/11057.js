const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString();

const dp = Array(1001)
  .fill()
  .map(() => Array(10).fill(0));

for (let i = 0; i < 10; i++) {
  dp[1][i] = 1;
}

for (let i = 2; i <= N; i++) {
  dp[i][0] = 1;
  for (let j = 1; j < 10; j++) {
    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
  }
}

const result = dp[N].reduce((a, b) => a + b, 0);
console.log(result % 10007);
