const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];

const ans = [];

while (true) {
  const [m, n] = getLine();
  if (m === 0 && n === 0) break;

  const parents = Array(m)
    .fill()
    .map((_, idx) => idx);

  const routes = [];

  for (let i = 0; i < n; i++) {
    routes.push(getLine());
  }

  routes.sort((a, b) => a[2] - b[2]);
  let result = 0;

  for (let i = 0; i < n; i++) {
    const [a, b, c] = routes[i];
    if (!sameParents(a, b)) {
      unionParents(a, b);
      continue;
    }
    result += c;
  }

  ans.push(result);

  function getParent(x) {
    if (parents[x] === x) return x;
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
}

console.log(ans.join('\n'));
