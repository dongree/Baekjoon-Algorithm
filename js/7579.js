const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [N, M] = inputs[0];
const values = inputs[1];
const weights = inputs[2];

const sum = weights.reduce((a, b) => a + b);

// dp[i][j] : i번까지 앱까지 확인했을 때 j의 비용으로 얻을 수 있는 최대 메모리 합
const dp = Array(N + 1)
  .fill()
  .map(() => Array(sum + 1).fill(0));

for (let i = 1; i <= N; i++) {
  const w = weights[i - 1];
  const v = values[i - 1];
  for (let j = 0; j <= sum; j++) {
    if (j < w) dp[i][j] = dp[i - 1][j];
    else {
      dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - w] + v);
    }
  }
}

for (let j = 0; j <= sum; j++) {
  if (dp[N][j] >= M) {
    console.log(j);
    break;
  }
}
