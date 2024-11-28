const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];

const [N, M] = getLine();

const A = getLine();
const B = getLine();

let ai = 0;
let bi = 0;
let result = 0;

while (ai < N && bi < M) {
  if (A[ai] >= B[bi]) {
    A[ai] -= B[bi];
    bi++;
  } else {
    result += A[ai];
    ai++;
  }
}

console.log(A.reduce((a, b) => a + b));
