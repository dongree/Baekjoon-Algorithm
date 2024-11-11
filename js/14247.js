const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const n = +inputs[0];
const H = inputs[1].split(' ').map(Number);
const A = inputs[2]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b)
  .map((e, i) => e * i);

const result = A.reduce((a, b) => a + b, 0) + H.reduce((a, b) => a + b, 0);
console.log(result);
