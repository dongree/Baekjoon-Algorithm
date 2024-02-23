const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1].split(' ').map(Number);

// dp[i] -> arr[i]를 포함하는 증가하는 부분 수열의 합
const dp = Array(N).fill(0);

for (let i = 0; i < N; i++) {
  max = 0;
  for (let j = 0; j < i; j++) {
    if (arr[j] < arr[i]) max = Math.max(max, dp[j]);
  }
  dp[i] = arr[i] + max;
}

console.log(Math.max(...dp));
