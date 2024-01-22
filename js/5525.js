const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const M = +inputs[1];
const S = inputs[2];

let i = 0;
let cnt = 0;
let answer = 0;

while (i <= M - 2) {
  if (S.substring(i, i + 3) === 'IOI') {
    i += 2;
    cnt += 1;
    if (cnt === N) {
      answer += 1;
      cnt -= 1;
    }
  } else {
    i += 1;
    cnt = 0;
  }
}

console.log(answer);
