const fs = require('fs');

const input = +fs.readFileSync('/dev/stdin').toString();

const dp = Array(41).fill(0);
let cnt1 = 0;
let cnt2 = 0;

fibRecursion(input);
fibDp(input);

console.log(cnt1, cnt2);

function fibRecursion(n) {
  if (n === 1 || n === 2) {
    cnt1++;

    return 1;
  } else return fibRecursion(n - 1) + fibRecursion(n - 2);
}

function fibDp(n) {
  dp[1] = 1;
  dp[2] = 1;
  for (let i = 3; i <= n; i++) {
    cnt2++;
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}
