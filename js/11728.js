const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().split('\n');

const A = inputs[1].split(' ').map(Number);
const B = inputs[2].split(' ').map(Number);

const result = [...A, ...B].sort((a, b) => a - b);
console.log(result.join(' '));
