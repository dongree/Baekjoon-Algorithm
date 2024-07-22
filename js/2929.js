const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

let i = 0;
let cnt = 4;
let result = 0;

while (i < s.length) {
  if (s[i] === s[i].toUpperCase()) {
    result += 4 - cnt;
    cnt = 1;
  } else {
    cnt++;
    if (cnt === 5) cnt = 1;
  }
  i++;
}

console.log(result);
