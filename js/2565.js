const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
let arr = [];
const dp = Array(N).fill(0);

for (let i = 1; i <= N; i++) {
  arr.push(inputs[i].split(' ').map(Number));
}

arr = arr.sort((a, b) => a[0] - b[0]).map((e) => e[1]);

for (let i = 0; i < N; i++) {
  let max = 0;
  for (let j = 0; j < i; j++) {
    if (arr[j] < arr[i]) max = Math.max(max, dp[j]);
  }
  dp[i] = max + 1;
}

const answer = N - Math.max(...dp);
console.log(answer);
