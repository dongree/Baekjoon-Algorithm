const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = inputs[0];
const arr = inputs[1].split(' ').map(Number);

const dp1 = Array(n).fill(0);
const dp2 = Array(n).fill(0);
const dp3 = Array(n).fill(0);

for (let i = 0; i < n; i++) {
  let max1 = 0;
  let max2 = 0;
  for (let j = 0; j < i; j++) {
    if (arr[j] < arr[i] && dp1[j] > max1) max1 = dp1[j];
    if (arr[n - j - 1] < arr[n - i - 1] && dp2[j] > max2) max2 = dp2[j];
  }
  dp1[i] = max1 + 1;
  dp2[i] = max2 + 1;
}

for (let i = 0; i < n; i++) {
  dp3[i] = dp1[i] + dp2[n - i - 1] - 1;
}

console.log(Math.max(...dp3));
