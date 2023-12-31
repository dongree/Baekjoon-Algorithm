const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];
const arr = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);
const x = +inputs[2];

let start = 0;
let end = n - 1;
let answer = 0;

while (start < end) {
  const a = arr[start] + arr[end];
  if (a <= x) {
    if (a === x) answer++;
    start++;
  } else {
    end--;
  }
}

console.log(answer);
