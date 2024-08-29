const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

let result = 0;

for (let i = 0; i < s.length; i++) {
  const n = +s[i];

  result += n * n * n * n * n;
}

console.log(result);
