const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const files = inputs[1].split(' ').map(Number);
const cluster = +inputs[2];

const result = files
  .map((file) => cluster * (Math.floor(file / cluster) + (file % cluster === 0 ? 0 : 1)))
  .reduce((a, b) => a + b);

console.log(result);
