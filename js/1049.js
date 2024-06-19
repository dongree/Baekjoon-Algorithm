const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [N, M] = inputs.shift();

const a = Math.floor(N / 6);
const b = N % 6;

let resA = Infinity;
let resB = Infinity;

inputs.forEach((e) => {
  const [i, j] = e;

  resA = Math.min(resA, a * i, a * j * 6);
  resB = Math.min(resB, i, j * b);
});

console.log(resA + resB);
