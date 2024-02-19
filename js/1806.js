const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, S] = inputs[0].split(' ').map(Number);
const arr = inputs[1].split(' ').map(Number);

let start = 0;
let end = 0;
let sum = arr[0];
let answer = 0;

while (start <= end && end < N) {
  if (sum >= S) {
    if (answer === 0) answer = end - start + 1;
    else answer = Math.min(answer, end - start + 1);
    sum -= arr[start++];
  } else {
    sum += arr[++end];
  }
}

console.log(answer);
