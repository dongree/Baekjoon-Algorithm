const fs = require('fs');

const S = fs.readFileSync('example.txt').toString().trim();

let one = S[0] === '0' ? 0 : 1;
let zero = S[0] === '0' ? 1 : 0;

let flag = S[0] === '0' ? '0' : '1';
for (let i = 1; i < S.length; i++) {
  if (S[i] !== flag) {
    flag = S[i] === '0' ? '0' : '1';
    if (flag === '1') {
      one++;
    } else zero++;
  }
}

console.log(Math.min(one, zero));
