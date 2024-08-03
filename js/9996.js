const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

let N = +getLine();
const pattern = getLine();

const [start, end] = pattern.split('*');
const regex = new RegExp(`^${start}[a-z]*${end}$`);
const result = [];

while (N--) {
  const s = getLine().trim();

  result.push(regex.test(s) ? 'DA' : 'NE');
}

console.log(result.join('\n'));
