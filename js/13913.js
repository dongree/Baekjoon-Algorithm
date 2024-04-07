const fs = require('fs');

const [N, K] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

const temp = Array(100001).fill(-1);

let idx = 0;
const q = [[N, 0]];

while (q.length !== idx) {
  const [x, cnt] = q[idx++];

  if (x == K) {
    console.log(cnt);
    break;
  }

  for (a of [x - 1, x + 1, 2 * x]) {
    if (inRange(a) && temp[a] == -1) {
      temp[a] = x;
      q.push([a, cnt + 1]);
    }
  }
}

const arr = [K];
let c = K;

while (c != N) {
  c = temp[c];
  arr.push(c);
}

console.log(arr.reverse().join(' '));

function inRange(x) {
  return 0 <= x && x <= 100000;
}
