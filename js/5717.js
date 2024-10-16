const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const result = [];

for (let i = 0; i < inputs.length - 1; i++) {
  result.push(inputs[i][0] + inputs[i][1]);
}

console.log(result.join('\n'));
