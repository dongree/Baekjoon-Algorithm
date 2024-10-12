const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString().trim().split('\n');

let cnt = 0;

for (let i = 1; i * i <= N; i++) {
  for (let j = i; j <= N; j++) {
    if (i * j <= N) cnt++;
    else break;
  }
}

console.log(cnt);
