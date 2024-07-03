const fs = require('fs');

const [N, ...arr] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

const dp = Array(1000001).fill(0);

dp[1] = 1;
dp[2] = 2;
dp[3] = 4;

for (let i = 4; i <= 1000000; i++) {
  dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
}

const results = [];
arr.forEach((e) => {
  results.push(dp[e]);
});

console.log(results.join('\n'));
