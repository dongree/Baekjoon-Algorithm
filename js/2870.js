const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];

const regex = /([0-9]+)/g;
const result = [];

for (let i = 1; i <= N; i++) {
  const url = inputs[i];
  const arr = url.match(regex);

  if (arr === null) continue;

  arr.forEach((e) => {
    result.push(BigInt(e).toString());
  });
}

console.log(result.sort((a, b) => a - b).join('\n'));
