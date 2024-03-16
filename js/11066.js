const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];

let [T] = getLine();

while (T--) {
  const [K] = getLine();
  const files = getLine();

  // dp[i][j] i부터 j까지 파일을 합쳤을 때 최소비용
  const dp = Array(K + 1)
    .fill()
    .map(() => Array(K + 1).fill(0));
  const sums = Array(K + 1).fill(0);

  for (let i = 0; i < K; i++) {
    sums[i + 1] = sums[i] + files[i];
  }
  for (let gap = 1; gap < K; gap++) {
    for (let start = 1; start <= K - gap; start++) {
      const end = start + gap;
      dp[start][end] = Infinity;
      for (let k = start; k < end; k++) {
        dp[start][end] = Math.min(
          dp[start][end],
          dp[start][k] + dp[k + 1][end] + sums[end] - sums[start - 1]
        );
      }
    }
  }
  console.log(dp);

  console.log(dp[1][K]);
}
