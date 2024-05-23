const fs = require('fs');

const [[N], ...arr] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

// dp[i][j][k] : k방향으로 i,j로 올수 있는 경우의 수
// k : 0-가로, 1-세로, 2-대각선

const dp = Array(N)
  .fill()
  .map(() =>
    Array(N)
      .fill()
      .map(() => Array(3).fill(0))
  );

dp[0][1][0] = 1;

for (let j = 2; j < N; j++) {
  if (arr[0][j] == 0) dp[0][j][0] = dp[0][j - 1][0];
}

for (let i = 1; i < N; i++) {
  for (let j = 1; j < N; j++) {
    if (arr[i][j] == 0) {
      dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
      dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];

      if (arr[i - 1][j] == 0 && arr[i][j - 1] == 0) {
        dp[i][j][2] =
          dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
      }
    }
  }
}

const ans = dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];

console.log(ans);
