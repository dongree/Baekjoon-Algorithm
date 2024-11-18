const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const T = +getLine();

const result = [];

for (let i = 1; i <= T; i++) {
  let s = `Scenario ${i}:\n`;
  const N = +getLine();
  const parents = Array(N)
    .fill()
    .map((_, i) => i);

  let k = +getLine();

  while (k--) {
    const [a, b] = getLine().split(' ').map(Number);
    unionParents(a, b);
  }

  let m = getLine();

  while (m--) {
    const [u, v] = getLine().split(' ').map(Number);
    s += +sameParent(u, v);
    s += '\n';
  }

  result.push(s);

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

  function sameParent(a, b) {
    a = getParent(a);
    b = getParent(b);

    return a === b;
  }
}

console.log(result.join('\n').trim());
