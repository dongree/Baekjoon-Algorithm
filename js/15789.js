const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];

const [N, M] = getLine();

const parents = Array(N + 1)
  .fill()
  .map((_, i) => i);

for (let i = 0; i < M; i++) {
  const [a, b] = getLine();

  unionParents(a, b);
}

let [C, H, K] = getLine();

const unions = {};

for (let i = 1; i <= N; i++) {
  const p = getParent(parents[i]);
  if (unions[p] === undefined) unions[p] = 1;
  else unions[p]++;
}

const arr = Object.entries(unions).sort((a, b) => b[1] - a[1]);
let result = unions[getParent(C)];

if (K === 0) console.log(result);
else {
  for (let i = 0; i < arr.length; i++) {
    const [p, cnt] = arr[i];

    if (sameParents(+p, C) || sameParents(+p, H)) continue;

    unionParents(+p, C);

    result += cnt;

    K--;
    if (K === 0) break;
  }

  console.log(result);
}

function getParent(x) {
  if (x === parents[x]) return x;
  else return (parents[x] = getParent(parents[x]));
}

function unionParents(a, b) {
  a = getParent(a);
  b = getParent(b);

  if (a > b) parents[a] = b;
  else if (a < b) parents[b] = a;
}

function sameParents(a, b) {
  a = getParent(a);
  b = getParent(b);

  return a === b;
}
