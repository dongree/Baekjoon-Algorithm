const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1].split(' ').map(Number);
const dp = Array(N).fill(0);

for (let i = 0; i < N; i++) {
  let k = 0;
  for (let j = 0; j < i; j++) {
    if (arr[i] < arr[j] && k < dp[j]) k = dp[j];
  }
  dp[i] = arr[i] + k;
}

console.log(Math.max(...dp));
