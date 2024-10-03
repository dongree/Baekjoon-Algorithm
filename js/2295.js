const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n').map(Number);

const [N, ...arr] = inputs;

const sum = [];

for (let i = 0; i < N; i++) {
  for (let j = i; j < N; j++) {
    sum.push(arr[i] + arr[j]);
  }
}

arr.sort((a, b) => a - b);
sum.sort((a, b) => a - b);

c: for (let k = N - 1; k >= 0; k--) {
  for (let z = k; z >= 0; z--) {
    const target = arr[k] - arr[z];

    if (binarySearch(target)) {
      console.log(arr[k]);
      break c;
    }
  }
}

function binarySearch(target) {
  let start = 0;
  let end = sum.length - 1;

  while (start <= end) {
    const mid = Math.floor((start + end) / 2);

    if (sum[mid] > target) end = mid - 1;
    else if (sum[mid] < target) start = mid + 1;
    else return true;
  }

  return false;
}
