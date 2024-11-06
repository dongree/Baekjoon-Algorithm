const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const ans = [];

for (let i = 0; i < inputs.length; i++) {
  const [N, S] = inputs[i];

  ans.push(Math.floor(S / (N + 1)));
}

console.log(ans.join('\n'));
