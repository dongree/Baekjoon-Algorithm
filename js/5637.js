const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

const regex = /[a-zA-Z-]+/g;
const candidates = s.match(regex);

let result = '';

for (let i = 0; i < candidates.length; i++) {
  if (candidates[i] === 'E-N-D') break;
  if (candidates[i].length > result.length) result = candidates[i];
}

console.log(result.toLowerCase());
