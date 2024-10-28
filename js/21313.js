const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString().trim();

let result = '1 2 '.repeat(Math.floor(N / 2));

if (N % 2 === 1) result += '3';

console.log(result.trim());
