const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const T = +getLine();
const result = [];

for (let t = 0; t < T; t++) {
  const [n, m] = getLine().split(' ').map(Number);

  const A = getLine().split(' ').map(Number);
  const B = getLine()
    .split(' ')
    .map(Number)
    .sort((a, b) => a - b);

  let sum = 0;

  for (let i = 0; i < n; i++) {
    const value = binarySearch(A[i]);

    sum += value;
  }

  result.push(sum);

  function binarySearch(target) {
    let start = 0;
    let end = m - 1;

    while (start + 1 < end) {
      const mid = Math.floor((start + end) / 2);

      if (B[mid] >= target) end = mid;
      else start = mid;
    }

    const a = Math.abs(target - B[start]);
    const b = Math.abs(target - B[end]);

    if (a <= b) return B[start];
    else return B[end];
  }
}

console.log(result.join('\n'));
