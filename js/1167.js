const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const V = +inputs[0];
const tree = Array(V + 1)
  .fill()
  .map(() => []);
const isVisited = Array(V + 1).fill(false);

for (let i = 1; i <= V; i++) {
  const [a, ...rest] = inputs[i].split(' ').map(Number);

  for (let j = 0; j < rest.length - 1; j += 2) {
    const b = rest[j];
    const dist = rest[j + 1];
    tree[a].push([dist, b]);
  }
}

let maxDist = 0;
let endPoint = 0;

isVisited[1] = true;
dfs(1, 0);
initIsVisited();
isVisited[endPoint] = true;
dfs(endPoint, 0);

console.log(maxDist);

function dfs(num, dist) {
  if (dist > maxDist) {
    maxDist = dist;
    maxDistNode = num;
  }
  maxDist = Math.max(maxDist, dist);
  for (let i = 0; i < tree[num].length; i++) {
    const nextNode = tree[num][i][1];
    const nextDist = dist + tree[num][i][0];
    if (!isVisited[nextNode]) {
      isVisited[nextNode] = true;
      dfs(nextNode, nextDist);
    }
  }
}

function initIsVisited() {
  for (let i = 1; i <= V; i++) {
    isVisited[i] = false;
  }
}
