const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m] = inputs[0].split(' ').map(Number);
const arr = inputs[1].split(' ').map(Number);
const dp = [0];
let result = [];

for (let i = 0; i < n; i++) {
  dp.push(dp[i] + arr[i]);
}

for (let i = 2; i < m + 2; i++) {
  const [a, b] = inputs[i].split(' ').map(Number);
  result.push(dp[b] - dp[a - 1]);
}

console.log(result.join('\n'));
