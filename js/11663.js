const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);
const dots = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);

const result = [];

for (let i = 2; i < M + 2; i++) {
  const [a, b] = inputs[i].split(' ').map(Number);

  result.push(bs2(b) - bs1(a) + 1);
}

console.log(result.join('\n'));

function bs1(k) {
  let start = 0;
  let end = N - 1;
  while (start <= end) {
    const mid = Math.floor((start + end) / 2);

    if (dots[mid] < k) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return start;
}

function bs2(k) {
  let start = 0;
  let end = N - 1;
  while (start <= end) {
    const mid = Math.floor((start + end) / 2);

    if (dots[mid] <= k) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return end;
}
