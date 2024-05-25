const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);
const adjList = Array(N + 1)
  .fill()
  .map(() => []);

for (let i = 1; i <= M; i++) {
  const [a, b] = inputs[i].split(' ').map(Number);
  adjList[b].push(a);
}

const ans = [];

const cnts = Array(N + 1).fill(0);

for (let i = 1; i <= N; i++) {
  const isVisited = Array(N + 1).fill(false);
  isVisited[i] = true;
  let cnt = 0;

  dfs(i);

  cnts[i] = cnt;

  function dfs(n) {
    cnt++;
    for (let i = 0; i < adjList[n].length; i++) {
      const nn = adjList[n][i];
      if (!isVisited[nn]) {
        isVisited[nn] = true;
        dfs(nn);
      }
    }
  }
}

const k = Math.max(...cnts);

for (let i = 1; i <= N; i++) {
  if (cnts[i] === k) ans.push(i);
}

console.log(ans.join(' '));
