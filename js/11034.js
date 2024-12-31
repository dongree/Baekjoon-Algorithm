const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const result = [];

for (let i = 0; i < inputs.length; i++) {
  const [A, B, C] = inputs[i];

  const k = Math.max(B - A - 1, C - B - 1);
  result.push(k);
}

console.log(result.join('\n'));
