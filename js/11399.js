const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];
const arr = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);

const time = [arr[0]];

for (let i = 1; i < n; i++) {
  time.push(time[i - 1] + arr[i]);
}

const answer = time.reduce((prev, curr) => prev + curr, 0);

console.log(answer);
