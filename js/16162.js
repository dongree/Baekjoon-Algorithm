const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, A, D] = inputs[0].split(' ').map(Number);
const arr = inputs[1].split(' ').map(Number);

let x = 1;

arr.forEach((e) => {
  if (expression(x) === e) x++;
});

console.log(x - 1);

function expression(x) {
  return D * (x - 1) + A;
}
