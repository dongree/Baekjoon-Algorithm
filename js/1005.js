const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];
const answer = [];

let [T] = getLine();

while (T--) {
  let [N, K] = getLine();
  const D = [0, ...getLine()];
  const adjList = Array(N + 1)
    .fill()
    .map(() => []);
  const dp = Array(N + 1).fill(0);
  const indegree = Array(N + 1).fill(0);

  while (K--) {
    const [a, b] = getLine();
    adjList[a].push(b);
    indegree[b]++;
  }
  const [W] = getLine();

  const q = [];

  for (let i = 1; i <= N; i++) {
    if (indegree[i] === 0) {
      q.push(i);
      dp[i] = D[i];
    }
  }
  while (q.length !== 0) {
    const curr = q.shift();

    for (const next of adjList[curr]) {
      if (dp[next] < D[next] + dp[curr]) dp[next] = D[next] + dp[curr];
      indegree[next]--;

      if (indegree[next] === 0) q.push(next);
    }
  }

  answer.push(dp[W]);
}

console.log(answer.join('\n'));
