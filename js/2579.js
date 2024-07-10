const fs = require('fs');

const [N, ...arr] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

const dp = Array(N + 1).fill(0);
arr.unshift(0);

dp[1] = arr[1];
dp[2] = arr[1] + arr[2];
dp[3] = Math.max(arr[1] + arr[3], arr[2] + arr[3]);

for (let i = 4; i <= N; i++) {
  dp[i] = Math.max(dp[i - 2] + arr[i], dp[i - 3] + arr[i] + arr[i - 1]);
}

console.log(dp[N]);
9;
