const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const result = [];

for (let i = 0; i < inputs.length; i++) {
  while (true) {
    const k = inputs[i].length;
    inputs[i] = inputs[i].replaceAll('BUG', '');
    if (k === inputs[i].length) break;
  }
  result.push(inputs[i]);
}

console.log(result.join('\n'));
