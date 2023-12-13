const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = Number(inputs[0]);
const arr = [];

for (let i = 1; i <= n; i++) {
  arr.push(inputs[i].split(' ').map(Number));
}

let result = '';

arr
  .sort((a, b) => (a[1] - b[1] === 0 ? a[0] - b[0] : a[1] - b[1]))
  .forEach((item) => {
    result += `${item[0]} ${item[1]}\n`;
  });

console.log(result);
