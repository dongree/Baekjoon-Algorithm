const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split(' ').map(Number);

inputs.sort((a, b) => a - b);

const [a, b, c] = inputs;

const result = a + b + Math.min(a + b - 1, c);

console.log(result);
