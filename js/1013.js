const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const T = +inputs[0];

const regex = /^((100+1+)|01)+$/;
const result = [];

for (let i = 1; i <= T; i++) {
  const s = inputs[i];

  result.push(regex.test(s) ? 'YES' : 'NO');
}

console.log(result.join('\n'));
