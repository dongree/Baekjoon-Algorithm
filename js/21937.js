const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [N, M] = inputs[0];

const adjList = Array(N + 1)
  .fill()
  .map(() => []);
const isViaited = Array(N + 1).fill(false);

for (let i = 1; i < inputs.length - 1; i++) {
  const [a, b] = inputs[i];
  adjList[b].push(a);
}

const X = inputs[inputs.length - 1][0];
let cnt = 0;

isViaited[X] = true;
dfs(X);

console.log(cnt);

function dfs(n) {
  for (let i = 0; i < adjList[n].length; i++) {
    const nn = adjList[n][i];
    if (isViaited[nn]) continue;
    isViaited[nn] = true;
    cnt++;
    dfs(nn);
  }
}
