const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((arr) => arr.split(' ').map(Number));

const [n, m] = inputs.shift();

const parent = Array(n)
  .fill()
  .map((_, i) => i);

console.log(solve());

function solve() {
  for (let i = 0; i < m; i++) {
    const [a, b] = inputs[i];
    if (!sameParent(a, b)) {
      unionParent(a, b);
    } else {
      return i + 1;
    }
  }

  return 0;
}

function getParent(k) {
  if (parent[k] === k) return k;
  else return (parent[k] = getParent(parent[k]));
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
