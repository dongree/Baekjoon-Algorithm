const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1].split(' ').map(Number);

const result = Array(N).fill(0);

let p1 = 0;
let p2 = 1;
let p3 = N - 1;

let n = N;

arr.forEach((e) => {
  if (e === 1) {
    result[p1] = n;
    p1 = p2;
    p2++;
  } else if (e === 2) {
    result[p2++] = n;
  } else {
    result[p3--] = n;
  }
  n--;
});

console.log(result.join(' '));
