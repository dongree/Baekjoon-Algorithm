const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [n, m] = inputs[0].split(' ').map(Number);
const heights = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);

let start = 0;
let end = heights[n - 1];
let answer = 0;

while (start <= end) {
  const mid = Math.floor((start + end) / 2);

  const woods = heights
    .map((h) => (h <= mid ? 0 : h - mid))
    .reduce((a, b) => a + b, 0);

  if (woods >= m) {
    start = mid + 1;
    answer = mid;
  } else {
    end = mid - 1;
  }
}

console.log(answer);
