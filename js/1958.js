const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const a = inputs[0];
const b = inputs[1];
const c = inputs[2];

const result = getLCS(a, b, c);
console.log(result);

function getLCS(a, b, c) {
  const n = a.length;
  const m = b.length;
  const k = c.length;

  const dp = Array(n + 1)
    .fill()
    .map(() =>
      Array(m + 1)
        .fill()
        .map(() => Array(k + 1).fill(0))
    );

  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= m; j++) {
      for (let l = 1; l <= k; l++) {
        if (a[i - 1] === b[j - 1] && b[j - 1] === c[l - 1]) {
          dp[i][j][l] = dp[i - 1][j - 1][l - 1] + 1;
        } else {
          dp[i][j][l] = Math.max(
            dp[i - 1][j][l],
            dp[i][j - 1][l],
            dp[i][j][l - 1]
          );
        }
      }
    }
  }

  return dp[n][m][k];
}
