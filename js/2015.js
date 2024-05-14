const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, K] = inputs[0].split(' ').map(Number);
const arr = [0, ...inputs[1].split(' ').map(Number)];

const dp = Array(N + 1).fill(0);
const dic = {};
let ans = 0;

for (let i = 1; i <= N; i++) {
  dp[i] = dp[i - 1] + arr[i];
  if (dp[i] === K) ans++;
}

for (let i = 1; i <= N; i++) {
  if (dic[dp[i] - K] !== undefined) {
    ans += dic[dp[i] - K];
  }

  if (dic[dp[i]] === undefined) dic[dp[i]] = 1;
  else dic[dp[i]]++;
}

console.log(ans);
