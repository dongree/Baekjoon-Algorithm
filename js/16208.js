const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);

let length = arr.reduce((a, b) => a + b, 0);
let k = 0;

for (let i = 0; i < N - 1; i++) {
  const sliced = length - arr[i];

  k += sliced * arr[i];
  length = sliced;
}

console.log(k);
