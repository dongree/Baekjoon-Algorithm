const fs = require('fs');

const [A, B, C] = fs.readFileSync('example.txt').toString().trim().split('\n');

console.log(+A + +B - +C);
console.log(A + B - C);
