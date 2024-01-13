const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, k] = inputs[0].split(' ').map(Number);

const goods = [0];

for (let i = 1; i <= n; i++) {
  const subArr = inputs[i].split(' ').map(Number);
  goods.push(subArr);
}

// dp[i][j] : 용량이 j일 때 i번까지 물품들 중 최적으로 고른 물품둘의 가치의 합
const dp = Array(n + 1)
  .fill()
  .map(() => Array(k + 1).fill(0));

for (let i = 1; i <= n; i++) {
  const [w, v] = goods[i];
  for (let j = 0; j <= k; j++) {
    if (j < w) dp[i][j] = dp[i - 1][j];
    else dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - w] + v);
  }
}

console.log(dp[n][k]);
