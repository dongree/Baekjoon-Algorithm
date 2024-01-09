const fs = require('fs');

let n = +fs.readFileSync('/dev/stdin').toString().trim();

const coins = [7, 5, 2, 1];
const dp = [0, 1, 1, 2, 2, 1, 2, 1];

for (let i = 8; i <= n; i++) {
  const min = Math.min(...coins.map((coin) => dp[i - coin]));
  dp[i] = min + 1;
}

console.log(dp[n]);
