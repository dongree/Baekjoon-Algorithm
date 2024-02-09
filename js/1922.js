const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const M = +inputs[1];
const parent = Array(N + 1)
  .fill()
  .map((_, idx) => idx);
const arr = [];
let answer = 0;

for (let i = 2; i < M + 2; i++) {
  const [a, b, c] = inputs[i].split(' ').map(Number);
  arr.push([c, a, b]);
}

arr.sort((a, b) => a[0] - b[0]);

let cnt = 0;
for (let i = 0; i < M; i++) {
  const [weight, from, to] = arr[i];

  if (!sameParent(from, to)) {
    unionParent(from, to);
    cnt++;
    answer += weight;
  }

  if (cnt === N - 1) break;
}

console.log(answer);

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
