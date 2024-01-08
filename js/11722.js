const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];
const a = inputs[1].split(' ').map(Number);
// dp[i] -> a[i]를 포함하는 가장 긴 감소하는 부분 수열의 길이
const dp = Array(n).fill(0);

for (let i = 0; i < n; i++) {
  let max = 0;

  for (let j = 0; j < i; j++) {
    if (a[i] < a[j] && dp[j] > max) max = dp[j];
  }
  dp[i] = max + 1;
}

console.log(Math.max(...dp));
