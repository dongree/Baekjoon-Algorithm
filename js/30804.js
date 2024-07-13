const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1].split(' ').map(Number);

const count = Array(10).fill(0);
let ans = 0;
let start = 0;
let end = 0;

while (end < N) {
  count[arr[end]]++;

  if (getTypeCnt() > 2) {
    count[arr[start++]]--;
  }

  ans = Math.max(ans, end - start + 1);
  end++;
}

console.log(ans);

function getTypeCnt() {
  return count.filter((e) => e !== 0).length;
}
