const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, K] = inputs[0].split(' ').map(Number);
const arr = inputs[1].split(' ').map(Number);

const dp = Array(N).fill(false);
dp[0] = true;

for (let i = 0; i < N; i++) {
  for (let j = i + 1; j < N; j++) {
    if (dp[i] && calcPower(i, j) <= K) {
      dp[j] = true;
    }
  }
}

console.log(dp[N - 1] ? 'YES' : 'NO');

function calcPower(i, j) {
  return (j - i) * (1 + Math.abs(arr[i] - arr[j]));
}
