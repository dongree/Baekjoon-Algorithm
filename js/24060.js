const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let cnt = 0;
let ans = -1;

const [N, K] = inputs[0];
const A = inputs[1];

mergeSort(A);
console.log(ans);

function merge(left, right) {
  const results = [];

  let i = 0;
  let j = 0;

  while (i < left.length && j < right.length) {
    if (left[i] < right[j]) {
      results.push(left[i]);
      cnt++;
      if (cnt === K) ans = left[i];
      i++;
    } else {
      results.push(right[j]);

      cnt++;
      if (cnt === K) ans = right[j];
      j++;
    }
  }

  while (i < left.length) {
    results.push(left[i]);
    cnt++;
    if (cnt === K) ans = left[i];
    i++;
  }
  while (j < right.length) {
    results.push(right[j]);
    cnt++;
    if (cnt === K) ans = right[j];
    j++;
  }

  return results;
}

function mergeSort(arr) {
  if (arr.length <= 1) return arr;

  const mid = Math.ceil(arr.length / 2);
  const left = mergeSort(arr.slice(0, mid));
  const right = mergeSort(arr.slice(mid));

  return merge(left, right);
}
