const fs = require('fs');

const [[N], ...W] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const dp = Array(N)
  .fill()
  .map(() => Array(1 << N).fill(-1));

function dfs(now, visited) {
  if (visited === (1 << N) - 1) {
    if (W[now][0] === 0) return Infinity;
    else return W[now][0];
  }

  if (dp[now][visited] !== -1) return dp[now][visited];
  dp[now][visited] = Infinity;

  for (let i = 0; i < N; i++) {
    if (W[now][i] === 0) continue;
    if (visited & (1 << i)) continue;
    dp[now][visited] = Math.min(
      dp[now][visited],
      W[now][i] + dfs(i, visited | (1 << i))
    );
  }
  return dp[now][visited];
}

console.log(dfs(0, 1));
