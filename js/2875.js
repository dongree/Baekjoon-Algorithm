const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let [N, M, K] = inputs[0].split(' ').map(Number);

let cnt = N + M;
let n = 0;

while (cnt - 3 >= K) {
  N -= 2;
  M -= 1;
  cnt -= 3;

  if (N < 0 || M < 0) break;

  n++;
}

console.log(n);
