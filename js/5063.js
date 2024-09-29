const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];

const result = [];

for (let i = 1; i <= N; i++) {
  const [r, e, c] = inputs[i].split(' ').map(Number);

  const p = e - c;

  if (r < p) result.push('advertise');
  else if (r === p) result.push('does not matter');
  else result.push('do not advertise');
}

console.log(result.join('\n'));
