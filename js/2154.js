const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString().trim();

let s = '';

for (let i = 1; i <= N; i++) {
  s += i.toString();
}

const result = s.indexOf(N.toString());

console.log(result + 1);
