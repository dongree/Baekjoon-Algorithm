const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [N, W] = inputs[0];
let cnt = 0;

const adjList = Array(N + 1)
  .fill()
  .map(() => []);
const isVisited = Array(N + 1).fill(false);

for (let i = 1; i < inputs.length; i++) {
  const [a, b] = inputs[i];
  adjList[a].push(b);
  adjList[b].push(a);
}

isVisited[1] = true;
dfs(1);
console.log(W / cnt);

function dfs(n) {
  let cnCnt = 0;
  for (let i = 0; i < adjList[n].length; i++) {
    const nn = adjList[n][i];
    if (!isVisited[nn]) {
      cnCnt++;
      isVisited[nn] = true;
      dfs(nn);
      isVisited[nn] = false;
    }
  }
  if (cnCnt === 0) cnt++;
}
