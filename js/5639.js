const fs = require('fs');

const arr = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

const ans = [];

postorder(0, arr.length);

console.log(ans.join('\n'));

function postorder(start, end) {
  if (start >= end) return;
  if (start === end - 1) {
    ans.push(arr[start]);
    return;
  }
  let idx = start + 1;

  while (idx < end) {
    if (arr[start] < arr[idx]) break;
    idx++;
  }

  postorder(start + 1, idx);
  postorder(idx, end);
  ans.push(arr[start]);
}
