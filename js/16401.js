const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [M, N] = inputs[0];
const arr = inputs[1];

arr.sort((a, b) => a - b);

let start = 1;
let end = arr[arr.length - 1];

while (start <= end) {
  const mid = Math.floor((start + end) / 2);

  if (isPossilbe(mid)) {
    start = mid + 1;
  } else {
    end = mid - 1;
  }
}

console.log(end);

function isPossilbe(k) {
  let sum = 0;
  for (let i = 0; i < N; i++) {
    sum += Math.floor(arr[i] / k);
  }

  return sum >= M;
}
