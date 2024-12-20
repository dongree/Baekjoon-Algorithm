const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1].split(' ').map(Number);

let cnt = 2;
let result = 0;

for (let i = 0; i < N - 2; i++) {
  if (arr[i] <= arr[i + 1] && arr[i + 1] <= arr[i + 2]) cnt = 2;
  else if (arr[i] >= arr[i + 1] && arr[i + 1] >= arr[i + 2]) cnt = 2;
  else cnt++;

  result = Math.max(result, cnt);
}

console.log(result);
