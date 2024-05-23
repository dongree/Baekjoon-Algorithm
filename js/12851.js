const fs = require('fs');

const [N, K] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

const isVisited = Array(100001).fill(false);

let idx = 0;
const q = [[N, 0]];

let ansT;
let ansCnt = 1;

while (q.length !== idx) {
  const [n, t] = q[idx++];
  isVisited[n] = true;

  if (n === K) {
    ansT = t;
    break;
  }

  if (inRange(n - 1) && !isVisited[n - 1]) q.push([n - 1, t + 1]);
  if (inRange(n + 1) && !isVisited[n + 1]) q.push([n + 1, t + 1]);
  if (inRange(n * 2) && !isVisited[n * 2]) q.push([n * 2, t + 1]);
}

while (q.length !== idx) {
  const [n, t] = q[idx++];

  if (t > ansT) break;

  if (n === K) ansCnt++;
}

console.log(ansT);
console.log(ansCnt);

function inRange(n) {
  return 0 <= n && n <= 100000;
}
