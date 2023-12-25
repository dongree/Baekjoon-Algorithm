const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m, r] = inputs[0].split(' ').map(Number);

const adjList = {};
const visited = Array(n).fill(false);

for (let i = 1; i <= n; i++) {
  adjList[i] = [];
}

for (let i = 1; i <= m; i++) {
  const [u, v] = inputs[i].split(' ').map(Number);
  adjList[u].push(v);
  adjList[v].push(u);
}

for (v in adjList) {
  adjList[v].sort((a, b) => b - a);
}

let count = 1;
const result = Array(n).fill(0);
dfs(r);
console.log(result.join('\n'));

function dfs(c) {
  if (visited[c]) return;

  visited[c] = true;
  result[c - 1] = count++;

  adjList[c].forEach((e) => {
    dfs(e, visited);
  });
}
