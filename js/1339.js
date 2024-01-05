const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];
const arr = [];
for (let i = 1; i <= n; i++) {
  arr.push(inputs[i]);
}
const obj = {};

arr.forEach((word) => {
  [...word].forEach((alphabet, i) => {
    if (!obj[alphabet]) obj[alphabet] = 0;
    obj[alphabet] += 10 ** (word.length - i - 1);
  });
});

const answer = Object.values(obj)
  .sort((a, b) => b - a)
  .reduce((prev, curr, i) => prev + curr * (9 - i), 0);

console.log(answer);
