const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const T = +inputs[0];

// dp[i][j] : j번째 번호를 시작으로 i길이의 만들 수 있는 비밀번호 수
const dp = Array(1001)
  .fill()
  .map((e) => Array(10).fill(0));

for (let i = 0; i < 10; i++) {
  dp[1][i] = 1;
}

for (let i = 2; i <= 1000; i++) {
  dp[i][0] = divide(dp[i - 1][7]);
  dp[i][1] = divide(dp[i - 1][2] + dp[i - 1][4]);
  dp[i][2] = divide(dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]);
  dp[i][3] = divide(dp[i - 1][2] + dp[i - 1][6]);
  dp[i][4] = divide(dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]);
  dp[i][5] = divide(dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]);
  dp[i][6] = divide(dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]);
  dp[i][7] = divide(dp[i - 1][0] + dp[i - 1][4] + dp[i - 1][8]);
  dp[i][8] = divide(dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9]);
  dp[i][9] = divide(dp[i - 1][6] + dp[i - 1][8]);
}

const result = [];

for (let i = 1; i <= T; i++) {
  const N = +inputs[i];

  let cnt = 0;
  for (let i = 0; i < 10; i++) {
    cnt += dp[N][i];
  }
  result.push(divide(cnt));
}

console.log(result.join('\n'));

function divide(n) {
  return n % 1234567;
}
