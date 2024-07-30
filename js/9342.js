const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = inputs[0];

const regex = /^[A-F]?A+F+C+[A-F]?$/;

for (let i = 1; i <= N; i++) {
  const s = inputs[i];

  if (regex.test(s)) console.log('Infected!');
  else console.log('Good');
}
