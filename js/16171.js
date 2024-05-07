const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const s = inputs[0]
  .split('')
  .filter((e) => !('0' <= e && e <= '9'))
  .join('');

const target = inputs[1];

console.log(+s.includes(target));
