const fs = require('fs');

const N = fs.readFileSync('example.txt').toString().trim();

let cnt = 0;

for (let i = 1; i <= N; i++) {
  const s = i.toString();
  for (let j = 0; j < s.length; j++) {
    if (s[j] === '3' || s[j] === '6' || s[j] === '9') {
      cnt++;
    }
  }
}

console.log(cnt);
