const fs = require('fs');

const [[N, M], ...inputs] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const adjList = Array(N + 1)
  .fill()
  .map(() => []);
const adjLis2 = Array(N + 1)
  .fill()
  .map(() => []);

inputs.forEach((e) => {
  const [a, b] = e;
  adjList[a].push(b);
  adjLis2[b].push(a);
});

const isVisited = Array(N + 1).fill(false);
let cnt = 0;
let ans = 0;

for (let i = 1; i <= N; i++) {
  cnt = 0;
  init(i);
  dfs(i, adjList);
  init(i);
  dfs(i, adjLis2);

  if (cnt === N - 1) ans++;
}

console.log(ans);

function init(k) {
  for (let i = 1; i <= N; i++) {
    isVisited[i] = false;
  }
  isVisited[k] = true;
}

function dfs(n, arr) {
  for (let i = 0; i < arr[n].length; i++) {
    const k = arr[n][i];
    if (!isVisited[k]) {
      isVisited[k] = true;
      cnt++;
      dfs(k, arr);
    }
  }
}
