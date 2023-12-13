const fs = require('fs');

const inputs = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

const [n, ...arr] = inputs;

arr.sort((a, b) => a - b).forEach((item) => console.log(item));
