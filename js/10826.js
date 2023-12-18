const fs = require('fs');

const n = +fs.readFileSync('/dev/stdin').toString().trim();

const dp = Array(n + 1)
  .fill()
  .map(() => BigInt(0));

dp[0] = BigInt(0);
dp[1] = BigInt(1);

for (let i = 2; i <= n; i++) {
  dp[i] = dp[i - 1] + dp[i - 2];
}

console.log(dp[n].toString());
