const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const M = +inputs[1];
const parent = Array(N)
  .fill()
  .map((_, idx) => idx);

for (let i = 2; i < N + 2; i++) {
  inputs[i].split(' ').forEach((e, j) => {
    if (+e === 1 && !sameParent(i - 1, j + 1)) {
      unionParent(i - 1, j + 1);
    }
  });
}

const plan = inputs[N + 2].split(' ').map(Number);

solve();

function solve() {
  for (let i = 0; i < M - 1; i++) {
    const from = plan[i];
    const to = plan[i + 1];
    if (!sameParent(from, to)) {
      console.log('NO');
      return;
    }
  }
  console.log('YES');
}

function getParent(x) {
  if (x === parent[x]) return x;
  else return (parent[x] = getParent(parent[x]));
}

function unionParent(a, b) {
  a = getParent(a);
  b = getParent(b);
  if (a < b) parent[b] = a;
  else parent[a] = b;
}

function sameParent(a, b) {
  a = getParent(a);
  b = getParent(b);
  return a === b;
}
