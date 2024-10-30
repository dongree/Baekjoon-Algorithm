const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];

const [N, M, H] = getLine();

// dp[i][j] : i번까지 학생의 블럭을 가지고 j 높이를 만들 수 있는 경우의 수
const dp = Array(N + 1)
  .fill()
  .map(() => Array(H + 1).fill(0));

const blocks = [[]];
for (let i = 0; i < N; i++) {
  blocks.push(getLine());
}

for (let i = 0; i <= N; i++) dp[i][0] = 1;
for (let i = 1; i <= N; i++) {
  for (let j = 1; j <= H; j++) {
    for (let k = 0; k < blocks[i].length; k++) {
      if (blocks[i][k] <= j) dp[i][j] = (dp[i][j] + dp[i - 1][j - blocks[i][k]]) % 10007;
    }
    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 10007;
  }
}

console.log(dp[N][H]);
