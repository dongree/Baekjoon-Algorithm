const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString().trim();
const result = [];

for (let i = 1; i <= N; i++) {
  result.push(i);
  if (i % 6 === 0) result.push('Go!');
}

if (result[result.length - 1] !== 'Go!') result.push('Go!');

console.log(result.join(' '));
