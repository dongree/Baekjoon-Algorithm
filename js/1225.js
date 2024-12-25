const fs = require('fs');

const [A, B] = fs.readFileSync('example.txt').toString().trim().split(' ');

let result = 0;

for (let i = 0; i < A.length; i++) {
  for (let j = 0; j < B.length; j++) {
    const res = +A[i] * +B[j];
    result += res;
  }
}

console.log(result);
