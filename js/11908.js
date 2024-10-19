const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];

const result = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b)
  .slice(0, N - 1)
  .reduce((a, b) => a + b, 0);

console.log(result);
