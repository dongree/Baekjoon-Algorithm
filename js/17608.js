const fs = require('fs');

const [N, ...arr] = fs.readFileSync('example.txt').toString().trim().split('\n').map(Number);

let cnt = 0;
let a = 0;

for (let i = N - 1; i >= 0; i--) {
  if (arr[i] > a) {
    a = arr[i];
    cnt++;
  }
}

console.log(cnt);
