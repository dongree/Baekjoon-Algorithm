const fs = require('fs');

const input = fs.readFileSync('/dev/stdin').toString().trim();

const a = input.split('-');

const aa = a.map((e) => {
  const b = e.split('+').map(Number);
  return b.reduce((prev, curr) => prev + curr, 0);
});

let answer = aa[0];
for (let i = 1; i < aa.length; i++) {
  answer = answer - aa[i];
}

console.log(answer);
