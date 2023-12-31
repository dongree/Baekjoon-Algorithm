const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];
const weight = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);

let start = 0;
let end = n - 1;
let minMixed = Infinity;
let answer = [weight[start], weight[end]];

while (start < end) {
  const mixed = weight[start] + weight[end];
  if (Math.abs(mixed) < Math.abs(minMixed)) {
    minMixed = mixed;
    answer[0] = weight[start];
    answer[1] = weight[end];
  }
  if (mixed === 0) break;

  if (mixed < 0) start++;
  else end--;
}

console.log(answer.join(' '));
