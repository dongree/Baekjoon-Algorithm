const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const s = inputs[1];

let hn = '';
let result = 0;

for (let i = 0; i < N; i++) {
  if (isFinite(s[i])) {
    hn += s[i];
  } else {
    if (hn.length <= 6) result += +hn;
    hn = '';
  }
}

if (hn !== '') result += +hn;

console.log(result);
