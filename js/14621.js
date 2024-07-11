const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const [N, M] = getLine().split(' ').map(Number);

const univ = getLine().split(' ');
const routes = [];
const parents = Array(N + 1)
  .fill()
  .map((_, i) => i);

for (let i = 0; i < M; i++) {
  const route = getLine().split(' ').map(Number);

  routes.push(route);
}

routes.sort((a, b) => a[2] - b[2]);

let cnt = 0;
let ans = 0;

for (let i = 0; i < M; i++) {
  const [from, to, weight] = routes[i];

  if (!sameParent(from, to) && univ[from - 1] !== univ[to - 1]) {
    unionParent(from, to);
    ans += weight;
    cnt++;
  }

  if (cnt === N - 1) break;
}

console.log(cnt === N - 1 ? ans : -1);

function getParent(x) {
  if (x === parents[x]) return x;
  else return (parents[x] = getParent(parents[x]));
}

function unionParent(a, b) {
  a = getParent(a);
  b = getParent(b);

  if (a < b) parents[b] = a;
  else if (a > b) parents[a] = b;
}

function sameParent(a, b) {
  a = getParent(a);
  b = getParent(b);

  return a === b;
}
