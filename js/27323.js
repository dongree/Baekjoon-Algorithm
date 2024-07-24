const fs = require('fs');

const [a, b] = fs.readFileSync('example.txt').toString().trim().split('\n').map(Number);

console.log(a * b);
