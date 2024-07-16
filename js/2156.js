// 첫번째 풀이
// const fs = require('fs');

// const [N, ...arr] = fs
//   .readFileSync('/dev/stdin')
//   .toString()
//   .trim()
//   .split('\n')
//   .map(Number);

// const dp = Array(N).fill(0); // dp[i] : i번 포도주를 포함해 마실 수 있는 최대 포도주 양

// dp[0] = arr[0];
// if (N > 1) dp[1] = arr[0] + arr[1];
// if (N > 2) dp[2] = Math.max(arr[0] + arr[2], arr[1] + arr[2]);

// for (let i = 3; i < N; i++) {
//   let k = 0;
//   for (let j = 0; j <= i - 2; j++) {
//     k = Math.max(k, dp[j] + arr[i]);
//     if (j >= 1) k = Math.max(k, dp[j - 1] + arr[i - 1] + arr[i]);
//   }
//   dp[i] = k;
// }

// console.log(Math.max(...dp));

const fs = require('fs');

const [N, ...arr] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

const dp = Array(N + 1).fill(0); // dp[i] : 잎에서부터 i개의 포도주 잔이 놓여있을 때 마실 수 있는 최대 포도주 양

dp[1] = arr[0];
dp[2] = arr[0] + arr[1];

for (let i = 3; i <= N; i++) {
  dp[i] = Math.max(
    dp[i - 3] + arr[i - 2] + arr[i - 1],
    dp[i - 2] + arr[i - 1],
    dp[i - 1]
  );
}

console.log(dp[N]);
