const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];

const strArr = Array(N).fill('');

let cnt1 = 0;
let cnt2 = 0;

for (let i = 1; i <= N; i++) {
  for (let j = 0; j < N; j++) {
    strArr[j] += inputs[i][j];
  }

  cnt1 += inputs[i].split('X').filter((s) => s.length >= 2).length;
}

strArr.forEach((e) => {
  cnt2 += e.split('X').filter((s) => s.length >= 2).length;
});

console.log(cnt1, cnt2);
