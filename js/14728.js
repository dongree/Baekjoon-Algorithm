const fs = require('fs');

const [[N, T], ...arr] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

// dp[i][j] 공부할 수 있는 총 시간이 j이고 i번째 단원까지 공부할 수 있을 때 얻을 수 있는 최대 점수
const dp = Array(N + 1)
  .fill()
  .map(() => Array(T + 1).fill(0));

for (let i = 0; i < N; i++) {
  const time = arr[i][0];
  const point = arr[i][1];
  for (let j = 1; j <= T; j++) {
    if (j < time) dp[i + 1][j] = dp[i][j];
    else dp[i + 1][j] = Math.max(dp[i][j], dp[i][j - time] + point);
  }
}

console.log(dp[N][T]);
