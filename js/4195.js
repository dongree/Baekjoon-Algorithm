const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

let T = +getLine();

const answer = [];

while (T--) {
  let F = +getLine();
  const dic = {};

  const parent = Array(200001)
    .fill()
    .map((_, i) => i);
  const firendsNum = Array(200001).fill(1);

  let nodeNum = 0;

  while (F--) {
    const [a, b] = getLine().split(' ');

    if (dic[a] === undefined) dic[a] = nodeNum++;
    if (dic[b] === undefined) dic[b] = nodeNum++;

    unionParent(dic[a], dic[b]);

    answer.push(firendsNum[getParent(dic[a])]);
  }

  function getParent(x) {
    if (x === parent[x]) return x;
    else return (parent[x] = getParent(parent[x]));
  }

  function unionParent(a, b) {
    a = getParent(a);
    b = getParent(b);
    if (a < b) {
      firendsNum[a] += firendsNum[b];
      parent[b] = a;
    } else if (a > b) {
      firendsNum[b] += firendsNum[a];
      parent[a] = b;
    }
  }
}

console.log(answer.join('\n'));
