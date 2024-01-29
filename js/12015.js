const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1].split(' ').map(Number);

const lis = [arr[0]];

for (let i = 1; i < N; i++) {
  if (lis[lis.length - 1] < arr[i]) {
    lis.push(arr[i]);
  } else {
    const idx = binarySearch(0, lis.length - 1, arr[i]);
    lis[idx] = arr[i];
  }
}

console.log(lis.length);

function binarySearch(start, end, target) {
  while (start < end) {
    const mid = Math.floor((start + end) / 2);

    if (lis[mid] < target) start = mid + 1;
    else end = mid;
  }

  return end;
}
