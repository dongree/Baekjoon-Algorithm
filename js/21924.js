const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];
let totalW = 0;
const edges = [];

let [N, M] = getLine();

const parents = Array(N + 1)
  .fill()
  .map((_, i) => i);

for (let i = 0; i < M; i++) {
  const [a, b, c] = getLine();
  totalW += c;
  edges.push([a, b, c]);
}

edges.sort((a, b) => a[2] - b[2]);

let w = 0;
let cnt = 0;

for (let i = 0; i < M; i++) {
  const [a, b, c] = edges[i];
  if (!sameParent(a, b)) {
    unionParent(a, b);
    w += c;
    cnt++;
  }

  if (cnt == N - 1) {
    break;
  }
}

let k = 0;
for (let i = 1; i <= N; i++) {
  if (parents[i] === i) k++;
}

console.log(k === 1 ? totalW - w : -1);

function getParent(x) {
  if (x === parents[x]) return x;
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
