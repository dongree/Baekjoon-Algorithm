const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const t = +inputs[0];
const answer = [];

for (let tc = 1; tc < t * 3; tc += 3) {
  const n = +inputs[tc];
  const coins = inputs[tc + 1].split(' ').map(Number);
  const price = +inputs[tc + 2];

  const dp = Array(price + 1).fill(0); //  dp[i] 주어진 동전들을 사용해 코인금액 i를 만들 수 있는 경우의 수
  dp[0] = 1;

  for (let i = 0; i < n; i++) {
    for (let j = coins[i]; j <= price; j++) {
      dp[j] += dp[j - coins[i]];
    }
  }

  answer.push(dp[price]);
}

console.log(answer.join('\n'));
