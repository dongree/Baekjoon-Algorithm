const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];

const dp = Array(n + 1)
  .fill()
  .map(() => Array(3).fill(0));

const [r, g, b] = inputs[1].split(' ').map(Number);
dp[1][0] = r;
dp[1][1] = g;
dp[1][2] = b;

for (let i = 2; i <= n; i++) {
  const [r, g, b] = inputs[i].split(' ').map(Number);

  dp[i][0] = r + Math.min(dp[i - 1][1], dp[i - 1][2]);
  dp[i][1] = g + Math.min(dp[i - 1][0], dp[i - 1][2]);
  dp[i][2] = b + Math.min(dp[i - 1][0], dp[i - 1][1]);
}

console.log(Math.min(...dp[n]));
