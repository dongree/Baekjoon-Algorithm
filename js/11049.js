const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const matrix = [];
// dp[i][j] - 행렬 i부터 j까지 곱했을 때 행렬의 최소 곱셈 연산 수
const dp = Array(N + 1)
  .fill()
  .map(() => Array(N + 1).fill(0));

for (let i = 1; i <= N; i++) {
  const [r, c] = inputs[i].split(' ').map(Number);
  matrix.push([r, c]);
}

for (let gap = 1; gap < N; gap++) {
  for (let start = 0; start < N - gap; start++) {
    const end = start + gap;
    dp[start][end] = Infinity;
    for (let k = start; k < end; k++) {
      dp[start][end] = Math.min(
        dp[start][end],
        dp[start][k] +
          dp[k + 1][end] +
          matrix[start][0] * matrix[k][1] * matrix[end][1]
      );
    }
  }
}

console.log(dp[0][N - 1]);
