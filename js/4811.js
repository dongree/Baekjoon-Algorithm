const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n').map(Number);

// dp[w][h] : W  w개와  H h개로 만들 수 있는 문자열 경우의 수
const dp = Array(31)
  .fill()
  .map(() => Array(31).fill(0n));

for (let w = 1; w <= 30; w++) {
  for (let h = 0; h <= w; h++) {
    if (h === 0) dp[w][h] = 1n;
    else dp[w][h] = dp[w - 1][h] + dp[w][h - 1];
  }
}

const result = [];
for (let i = 0; i < inputs.length - 1; i++) {
  const n = inputs[i];
  result.push(dp[n][n]);
}

console.log(result.join('\n'));
