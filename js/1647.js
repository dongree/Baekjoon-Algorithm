const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);

const arr = [];
const parent = Array(N + 1)
  .fill()
  .map((_, idx) => idx);
let answer = 0;
let cnt = 0;

for (let i = 1; i <= M; i++) {
  const [A, B, C] = inputs[i].split(' ').map(Number);
  arr.push([C, A, B]);
}

arr.sort((a, b) => a[0] - b[0]);

for (let i = 0; i < M; i++) {
  const [weight, from, to] = arr[i];
  if (!sameParent(from, to)) {
    unionParent(from, to);
    cnt++;
    answer += weight;
  }

  if (cnt === N - 2) break;
}

if (N === 2) console.log(0);
else console.log(answer);

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
