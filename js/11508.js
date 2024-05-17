const fs = require('fs');

const [N, ...arr] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

const result = arr
  .sort((a, b) => b - a)
  .map((e, i) => (i % 3 === 2 ? 0 : e))
  .reduce((a, b) => a + b);

console.log(result);
