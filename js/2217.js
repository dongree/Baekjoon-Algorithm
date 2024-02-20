const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];

const ropes = [];
let answer = 0;

for (let i = 1; i <= N; i++) {
  ropes.push(+inputs[i]);
}

ropes.sort((a, b) => a - b);

let n = N;
ropes.forEach((rope) => {
  answer = Math.max(answer, rope * n--);
});

console.log(answer);
