const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [N] = inputs[0];
const qORs = inputs[1];
const queuestack = inputs[2];
const M = inputs[3];
const arr = inputs[4];
const temp = [];

for (let i = N - 1; i >= 0; i--) {
  if (qORs[i] === 0) {
    temp.push(queuestack[i]);
  }
}

const ans = [...temp, ...arr].slice(0, M);
console.log(ans.join(' '));
