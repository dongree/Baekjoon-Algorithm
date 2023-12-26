const fs = require('fs');

const [n, k] = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

const visited = Array(100001).fill(false);

const q = [[n, 0]];
let idx = 0;

while (q.length !== 0) {
  const [loc, second] = q[idx++];
  if (loc === k) {
    console.log(second);
    break;
  }
  for (next of [loc - 1, loc + 1, 2 * loc]) {
    if (0 <= next && next <= 100000 && !visited[next]) {
      visited[next] = true;
      q.push([next, second + 1]);
    }
  }
}
