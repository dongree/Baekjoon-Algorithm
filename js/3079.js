const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);
const arr = [];
let maxV = -Infinity;

for (let i = 1; i <= N; i++) {
  const n = BigInt(inputs[i]);
  arr.push(n);
  if (n > maxV) maxV = n;
}

let start = 0n;
let end = BigInt(M) * maxV;

while (start <= end) {
  const mid = (start + end) / 2n;
  let cnt = 0n;
  for (let i = 0; i < arr.length; i++) {
    cnt += mid / arr[i];
  }

  if (cnt >= M) {
    end = mid - 1n;
  } else {
    start = mid + 1n;
  }
}

console.log(start.toString());
