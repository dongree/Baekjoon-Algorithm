const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];

const cost = [[0, 0, 0]];
let answer = Infinity;

for (let i = 1; i <= N; i++) {
  cost.push(inputs[i].split(' ').map(Number));
}

for (let start = 0; start <= 2; start++) {
  const dp = Array(N + 1)
    .fill()
    .map(() => Array(3).fill(0));

  for (let j = 0; j < 3; j++) {
    if (j === start) dp[1][start] = cost[1][start];
    else dp[1][j] = Infinity;
  }

  for (let i = 2; i <= N; i++) {
    dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
    dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
    dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
  }

  for (let j = 0; j < 3; j++) {
    if (start === j) continue;
    answer = Math.min(answer, dp[N][j]);
  }
}

console.log(answer);
