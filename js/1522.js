const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();
const len = s.split('a').length - 1;

const newS = s + s.substring(0, len - 1);
let ans = len;

for (let i = 0; i <= newS.length - len; i++) {
  ans = Math.min(ans, newS.substring(i, i + len).split('b').length - 1);
}

console.log(ans);
