const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const [n, m] = inputs[0].split(' ').map(Number);
const isVisited = Array(101).fill(-1);
const move = new Map();

for (let i = 1; i <= n + m; i++) {
  const [x, y] = inputs[i].split(' ').map(Number);
  move.set(x, y);
}

const q = [1];
isVisited[1] = 0;
let idx = 0;

while (q.length !== idx) {
  const loc = q[idx++];

  for (let i = 6; i >= 1; i--) {
    const nextLoc = move.get(loc + i) ? move.get(loc + i) : loc + i;

    if (isVisited[nextLoc] === -1) {
      isVisited[nextLoc] = isVisited[loc] + 1;
      q.push(nextLoc);
    }
  }
}

console.log(isVisited[100]);
