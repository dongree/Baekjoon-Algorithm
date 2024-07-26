const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

const N = s.length;

let R = 1;
let C = N;

for (let i = 1; i * i <= N; i++) {
  if (N % i === 0) {
    R = i;
    C = N / i;
  }
}

let result = '';

for (let i = 0; i < R; i++) {
  for (let j = 0; j < N; j += R) {
    result += s[j + i];
  }
}

console.log(result);
