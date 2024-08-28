const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

let T = +getLine();

const result = [];

while (T--) {
  let N = +getLine();
  while (N--) {
    const [a, b] = getLine().split(' ').map(Number);
    result.push(`${a + b} ${a * b}`);
  }
}

console.log(result.join('\n'));
