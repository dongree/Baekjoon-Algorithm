const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);
const arr = [];
for (let i = 1; i <= N; i++) {
  arr.push(+inputs[i]);
}

let start = Math.max(...arr);
let end = arr.reduce((a, b) => a + b, 0);

while (start <= end) {
  const mid = Math.floor((start + end) / 2);

  let sum = 0;
  let cnt = 1;
  arr.forEach((e) => {
    if (sum + e > mid) {
      sum = 0;
      cnt++;
    }
    sum += e;
  });

  if (cnt <= M) {
    end = mid - 1;
  } else {
    start = mid + 1;
  }
}

console.log(start);
