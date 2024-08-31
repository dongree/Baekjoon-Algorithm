const fs = require('fs');

const [N, M, ...arr] = fs.readFileSync('example.txt').toString().trim().split('\n').map(Number);

const isVip = Array(N + 1).fill(false);
const dp = Array(N + 1).fill(false);

arr.forEach((e) => (isVip[e] = true));

dp[0] = 1;
dp[1] = 1;
dp[2] = 2;

for (let i = 3; i <= 40; i++) {
  dp[i] = dp[i - 1] + dp[i - 2];
}

let cnt = 0;
let result = 1;
for (let i = 1; i <= N; i++) {
  if (isVip[i]) {
    result *= dp[cnt];
    cnt = 0;
    continue;
  }

  cnt++;
}

console.log(result * dp[cnt]);
