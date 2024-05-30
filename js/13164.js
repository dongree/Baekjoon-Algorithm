const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, K] = inputs[0].split(' ').map(Number);
const arr = inputs[1].split(' ').map(Number);

const diff = [];

for (let i = 0; i < N - 1; i++) {
  diff.push(arr[i + 1] - arr[i]);
}

diff.sort((a, b) => a - b);

let ans = 0;
for (let i = 0; i < N - K; i++) {
  ans += diff[i];
}

console.log(ans);
