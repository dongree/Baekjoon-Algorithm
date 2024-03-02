// bfs
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
const indegree = Array(N + 1).fill(0);
const q = [];
const answer = [];

for (let i = 1; i <= M; i++) {
  const [a, b] = inputs[i];
  adjList[a].push(b);
  indegree[b]++;
}

for (let i = 1; i <= N; i++) {
  if (indegree[i] === 0) {
    q.push(i);
  }
}

while (q.length) {
  const curr = q.shift();
  answer.push(curr);

  for (const next of adjList[curr]) {
    indegree[next]--;
    if (indegree[next] === 0) q.push(next);
  }
}

console.log(answer.join(' '));

// dfs

// const fs = require('fs');

// const inputs = fs
//   .readFileSync('example.txt')
//   .toString()
//   .trim()
//   .split('\n')
//   .map((e) => e.split(' ').map(Number));

// const [N, M] = inputs[0];
// const adjList = Array(N + 1)
//   .fill()
//   .map(() => []);
// const isVisited = Array(N + 1).fill(false);
// const stack = [];

// for (let i = 1; i <= M; i++) {
//   const [a, b] = inputs[i];
//   adjList[a].push(b);
// }

// for (let i = 1; i <= N; i++) {
//   if (!isVisited[i]) {
//     dfs(i);
//   }
// }

// console.log(stack.reverse().join(' '));

// function dfs(s) {
//   isVisited[s] = true;

//   for (let i = 0; i < adjList[s].length; i++) {
//     const next = adjList[s][i];
//     if (!isVisited[next]) {
//       dfs(next);
//     }
//   }
//   stack.push(s);
// }
