const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const arr = [];

const [n, m] = inputs[0].split(' ').map(Number);
for (let i = 1; i <= n; i++) {
  const subArr = inputs[i].split(' ').map(Number);
  arr.push(subArr);
}

const answer = [];

const dp = Array(n + 1)
  .fill()
  .map(() => Array(n + 1).fill(0));

for (let i = 1; i <= n; i++) {
  for (let j = 1; j <= n; j++) {
    dp[i][j] =
      arr[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
  }
}

for (let t = n + 1; t < n + m + 1; t++) {
  const [x1, y1, x2, y2] = inputs[t].split(' ').map(Number);

  answer.push(
    dp[x2][y2] - (dp[x1 - 1][y2] + dp[x2][y1 - 1]) + dp[x1 - 1][y1 - 1]
  );
}

console.log(answer.join('\n'));
