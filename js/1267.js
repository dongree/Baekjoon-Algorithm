const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1].split(' ').map(Number);

let Y = 0;
let M = 0;
arr.forEach((e) => {
  Y += 10 * (Math.floor(e / 30) + 1);
  M += 15 * (Math.floor(e / 60) + 1);
});

if (Y < M) {
  console.log('Y', Y);
} else if (Y > M) {
  console.log('M', M);
} else {
  console.log('Y', 'M', Y);
}
