const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, k] = inputs[0].split(' ').map(Number);
const arr = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => b - a);

console.log(arr[k - 1]);
