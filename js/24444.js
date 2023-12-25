const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m, r] = inputs[0].split(' ').map(Number);
const adjList = Array(n + 1)
  .fill()
  .map(() => []);
const visited = Array(n + 1).fill(false);
const result = Array(n).fill(0);

for (let i = 1; i <= m; i++) {
  const [u, v] = inputs[i].split(' ').map(Number);
  adjList[u].push(v);
  adjList[v].push(u);
}

adjList.forEach((arr) => arr.sort((a, b) => a - b));

const q = [];
let idx = 0;
let cnt = 1;

bfs();
console.log(result.join('\n'));

function bfs() {
  visited[r] = true;
  q.push(r);
  while (q.length !== idx) {
    let poped = q[idx++];
    result[poped - 1] = cnt++;
    adjList[[poped]].forEach((e) => {
      if (!visited[e]) {
        visited[e] = true;
        q.push(e);
      }
    });
  }
}
