const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

let T = +getLine();

const result = [];

while (T--) {
  const N = +getLine();
  const arr = getLine()
    .split(' ')
    .map((e) => +e);

  const min = Math.min(...arr);
  const max = Math.max(...arr);

  result.push(`${min} ${max}`);
}

console.log(result.join('\n'));
