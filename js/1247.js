const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n').map(BigInt);

let idx = 0;
const getLine = () => inputs[idx++];
const result = [];

for (let i = 0; i < 3; i++) {
  let t = getLine();

  let sum = 0n;
  while (t--) {
    sum += getLine();
  }

  if (sum === 0n) result.push('0');
  else if (sum > 0n) result.push('+');
  else result.push('-');
}

console.log(result.join('\n'));
