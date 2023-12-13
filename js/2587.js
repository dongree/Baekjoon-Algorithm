const fs = require('fs');

const inputs = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n')
  .map(Number)
  .sort((a, b) => a - b);

const middle = inputs[2];
const mean = inputs.reduce((pre, cur) => pre + cur, 0) / 5;

console.log(mean);
console.log(middle);
