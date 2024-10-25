const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1].split(' ').map(Number);
const K = +inputs[2];
let cnt = 0;
let root = 0;

const isVisited = Array(N).fill(false);
const tree = Array(N)
  .fill()
  .map(() => []);

for (let i = 0; i < N; i++) {
  if (arr[i] === -1) {
    root = i;
    continue;
  }

  tree[arr[i]].push(i);
}

dfs(root);

console.log(cnt);

function dfs(n) {
  if (n === K) return -1;

  if (tree[n].length === 0) {
    cnt++;
    return 0;
  }

  for (let i = 0; i < tree[n].length; i++) {
    const node = tree[n][i];
    if (isVisited[node]) continue;

    isVisited[node] = true;
    const temp = dfs(node);
    if (temp === -1 && tree[n].length === 1) cnt++;
    isVisited[node] = false;
  }

  return 0;
}
