const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [V, E] = inputs[0].split(' ').map(Number);

const parent = Array(V + 1)
  .fill()
  .map((_, idx) => idx);
const arr = [];
let answer = 0;

for (let i = 1; i <= E; i++) {
  const [A, B, C] = inputs[i].split(' ').map(Number);
  arr.push([C, A, B]);
}

arr.sort((a, b) => a[0] - b[0]);

let cnt = 0;
for (let i = 0; i < E; i++) {
  const [weight, from, to] = arr[i];

  if (!sameParent(from, to)) {
    unionParent(from, to);
    answer += weight;
    cnt++;
  }

  if (cnt === V - 1) break;
}

console.log(answer);

function getParent(x) {
  if (x === parent[x]) return x;
  else return (parent[x] = getParent(parent[x]));
}

function unionParent(a, b) {
  a = getParent(a);
  b = getParent(b);
  parent[b] = a;
}

function sameParent(a, b) {
  a = getParent(a);
  b = getParent(b);
  return a === b;
}
