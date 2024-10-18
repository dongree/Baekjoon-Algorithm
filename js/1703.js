const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];
const result = [];

while (true) {
  const input = getLine();

  if (input === '0') break;

  const [n, ...arr] = input.split(' ').map(Number);

  let value = 1;

  for (let i = 0; i < n; i++) {
    const a = arr[2 * i];
    const b = arr[2 * i + 1];
    value *= a;
    value -= b;
  }

  result.push(value);
}

console.log(result.join('\n'));
