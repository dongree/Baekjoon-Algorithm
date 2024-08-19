const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = [];

for (let i = 1; i <= N; i++) {
  arr.push(inputs[i].split(' ').map(Number));
}

const edges = [];

for (let i = 0; i < N; i++) {
  for (let j = i + 1; j < N; j++) {
    edges.push([i + 1, j + 1, arr[i][j]]);
  }
}

const parents = Array(N + 1)
  .fill()
  .map((_, i) => i);

edges.sort((a, b) => a[2] - b[2]);
let result = 0;
let cnt = 0;

for (let i = 0; i < edges.length; i++) {
  const [a, b, cost] = edges[i];

  if (!sameParent(a, b)) {
    unionParent(a, b);
    result += cost;
    cnt++;
  }

  if (cnt === N - 1) break;
}

console.log(result);

function getParent(x) {
  if (parents[x] === x) return x;
  else return (parents[x] = getParent(parents[x]));
}

function unionParent(a, b) {
  a = getParent(a);
  b = getParent(b);

  if (a > b) parents[a] = b;
  else if (a < b) parents[b] = a;
}

function sameParent(a, b) {
  a = getParent(a);
  b = getParent(b);

  return a === b;
}
