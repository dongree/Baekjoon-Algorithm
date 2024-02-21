const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);

let min = Infinity;
const answer = Array(3).fill(0);

for (let start = 0; start < N - 2; start++) {
  let mid = start + 1;
  let end = N - 1;
  while (mid < end) {
    const sum = arr[start] + arr[mid] + arr[end];
    if (Math.abs(sum) < min) {
      min = Math.abs(sum);
      answer[0] = arr[start];
      answer[1] = arr[mid];
      answer[2] = arr[end];
    }
    if (sum < 0) mid++;
    else end--;
  }
}

console.log(answer.join(' '));
