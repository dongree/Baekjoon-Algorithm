const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1].split(' ').map(Number);

if (arr[0] > 0) {
  console.log(arr[0], arr[1]);
} else if (arr[N - 1] < 0) {
  console.log(arr[N - 2], arr[N - 1]);
} else {
  let start = 0;
  let end = N - 1;
  let min = Math.abs(arr[start] + arr[end]);
  const answer = [arr[start], arr[end]];

  while (start < end) {
    if (Math.abs(arr[start] + arr[end]) <= min) {
      min = Math.abs(arr[start] + arr[end]);
      answer[0] = arr[start];
      answer[1] = arr[end];
    }

    if (Math.abs(arr[start]) < Math.abs(arr[end])) {
      end--;
    } else {
      start++;
    }
  }

  console.log(answer.join(' '));
}
