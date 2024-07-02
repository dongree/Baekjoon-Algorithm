const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

const dp = Array(251).fill(0n);

dp[0] = 1n;
dp[1] = 1n;
dp[2] = 3n;

for (let i = 3; i <= 250; i++) {
  dp[i] = dp[i - 1] + dp[i - 2] * 2n;
}

const results = [];
inputs.forEach((e) => {
  results.push(dp[e].toString());
});

console.log(results.join('\n'));
