const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString().trim();

console.log(2 ** N);
