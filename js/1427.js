const fs = require('fs');

const input = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('')
  .map(Number)
  .sort((a, b) => b - a)
  .join('');

console.log(input);
