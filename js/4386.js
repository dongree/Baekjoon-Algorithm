const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];

let [n] = getLine();

const coords = [];
for (let i = 0; i < n; i++) {
  coords.push(getLine());
}

const edges = [];

for (let i = 0; i < coords.length; i++) {
  const [x1, y1] = coords[i];
  for (let j = i + 1; j < coords.length; j++) {
    const [x2, y2] = coords[j];
    const weight =
      Math.floor(Math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2) * 100) / 100;
    edges.push([i, j, weight]);
  }
}

edges.sort((a, b) => a[2] - b[2]);

const parent = Array(n)
  .fill()
  .map((_, i) => i);

let answer = 0;
for (let i = 0; i < edges.length; i++) {
  const [a, b, weight] = edges[i];

  if (!sameParent(a, b)) {
    unionParent(a, b);
    answer += weight;
  }
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
