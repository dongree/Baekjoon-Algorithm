const fs = require('fs');

const [A, B, C, D] = fs.readFileSync('example.txt').toString().trim().split(' ');

console.log(Number(A + B) + Number(C + D));
