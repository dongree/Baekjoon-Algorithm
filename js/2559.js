const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, k] = inputs[0].split(' ').map(Number);
const arr = inputs[1].split(' ').map(Number);
const sum = [0];

for (let i = 0; i < n; i++) {
  sum.push(sum[i] + arr[i]);
}

let result = -Infinity;
for (let i = k; i <= n; i++) {
  if (sum[i] - sum[i - k] > result) result = sum[i] - sum[i - k];
}

console.log(result);
