const fs = require('fs');

const n = +fs.readFileSync('example.txt').toString().trim();

const dp = Array(n + 1).fill(0);

dp[1] = 1;
dp[2] = 1;

for (let i = 3; i <= n; i++) {
  dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
}

console.log(dp[n]);
