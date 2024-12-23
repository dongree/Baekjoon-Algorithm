const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n').map(Number);

const result = [];

for (let i = 0; i < inputs.length - 1; i++) {
  const n = +inputs[i];

  let star = '*';
  for (let j = 0; j < n; j++) {
    result.push(star);
    star += '*';
  }
}

console.log(result.join('\n'));
