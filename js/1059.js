const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const L = +inputs[0];
const arr = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);

const n = +inputs[2];

let start = 0;
let end = 1000;

for (let i = 0; i < L; i++) {
  if (arr[i] > n) {
    if (i == 0) {
      end = arr[i];
    } else {
      start = arr[i - 1];
      end = arr[i];
    }
    break;
  }
}

let cnt = 0;
for (let i = start + 1; i <= n; i++) {
  for (let j = i + 1; j < end; j++) {
    if (j < n) continue;
    cnt++;
  }
}

console.log(cnt);
