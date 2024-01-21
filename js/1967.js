const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');
const n = +inputs[0];

const adjList = Array(n + 1)
  .fill()
  .map(() => []);
const isVisited = Array(n + 1).fill(false);
let endPoint = 0;
let result = 0;

for (let i = 1; i < n; i++) {
  const [a, b, c] = inputs[i].split(' ').map(Number);

  adjList[a].push([b, c]);
  adjList[b].push([a, c]);
}

isVisited[1] = true;
dfs(1, 0);

init();

isVisited[endPoint] = true;
dfs(endPoint, 0);

console.log(result);

function init() {
  for (let i = 1; i <= n; i++) {
    isVisited[i] = false;
  }
}
function dfs(node, weight) {
  if (result < weight) {
    endPoint = node;
    result = weight;
  }

  for (let i = 0; i < adjList[node].length; i++) {
    const nextNode = adjList[node][i][0];
    const nextWeight = adjList[node][i][1];
    if (!isVisited[nextNode]) {
      isVisited[nextNode] = true;
      dfs(nextNode, weight + nextWeight);
    }
  }
}
