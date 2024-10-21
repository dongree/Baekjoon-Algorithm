const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const M = +inputs[1];
const arr = inputs[2].split(' ').map(Number);

let h = 1;
while (true) {
  let k = 0;
  let flag = true;
  for (let i = 0; i < M; i++) {
    if (arr[i] - h > k) {
      flag = false;
      break;
    } else {
      k = arr[i] + h;
    }
  }
  if (flag) break;

  h++;
}

h = Math.max(h, N - arr[M - 1]);

console.log(h);
