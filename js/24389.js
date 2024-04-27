const fs = require('fs');

let N = +fs.readFileSync('example.txt').toString().trim();
let M = ~N + 1;

let cnt = 0;

for (let i = 0; i < 32; i++) {
  if ((N & 1) != (M & 1)) cnt++;
  N >>= 1;
  M >>= 1;
}

console.log(cnt);
