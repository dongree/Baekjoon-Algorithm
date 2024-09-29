const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString();

const DIVIDER = 1000000007n;
const dp = Array(1000001).fill(0n);
dp[0] = 1n;
dp[1] = 2n;
dp[2] = 7n;

let sum = 0n;

for (let i = 3; i <= N; i++) {
  sum = (sum + 2n * dp[i - 3]) % DIVIDER;
  dp[i] = (dp[i - 1] * 2n + dp[i - 2] * 3n + sum) % DIVIDER;
}

console.log(dp[N].toString());
