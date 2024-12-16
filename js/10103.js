const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const n = +inputs[0];

let chang = 100;
let jeong = 100;

for (let i = 1; i <= n; i++) {
  const [a, b] = inputs[i].split(' ').map(Number);

  if (a > b) jeong -= a;
  else if (a < b) chang -= b;
}

console.log(chang);
console.log(jeong);
