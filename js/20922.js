const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [N, K] = inputs[0];
const arr = inputs[1];
const counting = Array(100001).fill(0);

let i = 0;
let j = 0;
let ans = 1;

counting[arr[i]]++;

while (j < N && i <= j) {
  if (j + 1 < N && counting[arr[j + 1]] < K) {
    counting[arr[j + 1]]++;
    j++;
  } else {
    if (i === j) j++;
    else counting[arr[i]]--;
    i++;
  }

  ans = Math.max(ans, j - i + 1);
}

console.log(ans);
