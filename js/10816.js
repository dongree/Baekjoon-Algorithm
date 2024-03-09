const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const arr = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);

const answer = [];

inputs[3].split(' ').forEach((e) => {
  const ub = upperBound(+e);
  const lb = lowerBound(+e);
  answer.push(ub - lb);
});

console.log(answer.join('\n'));

function lowerBound(target) {
  let start = 0;
  let end = arr.length;

  while (start < end) {
    const mid = Math.floor((start + end) / 2);
    if (arr[mid] >= target) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }

  return end;
}

function upperBound(target) {
  let start = 0;
  let end = arr.length;

  while (start < end) {
    const mid = Math.floor((start + end) / 2);
    if (arr[mid] > target) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }

  return end;
}
