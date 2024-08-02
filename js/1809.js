const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n').map(Number);

const result = [];

for (let i = 0; i < inputs.length - 1; i++) {
  const n = inputs[i];
  result.push((n * (n + 1)) / 2);
}

console.log(result.join('\n'));
