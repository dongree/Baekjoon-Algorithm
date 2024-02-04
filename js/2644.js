const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const n = +inputs[0];
const [a, b] = inputs[1].split(' ').map(Number);
const m = +inputs[2];
const adjList = Array(n + 1)
  .fill()
  .map(() => []);
const isVisited = Array(n + 1).fill(false);
let answer = -1;

for (let i = 3; i < m + 3; i++) {
  const [x, y] = inputs[i].split(' ').map(Number);
  adjList[x].push(y);
  adjList[y].push(x);
}

isVisited[a] = true;
dfs(a, 0);
console.log(answer);

function dfs(n, cnt) {
  if (n === b) {
    answer = cnt;
    return;
  }

  for (let i = 0; i < adjList[n].length; i++) {
    if (!isVisited[adjList[n][i]]) {
      isVisited[adjList[n][i]] = true;
      dfs(adjList[n][i], cnt + 1);
    }
  }
}
