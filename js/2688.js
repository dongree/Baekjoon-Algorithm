const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n').map(Number);

// dp[i][j] : i번째 자릿수 값이 j일때 줄어들지 않는 수의 개수
const dp = Array(65)
  .fill()
  .map(() => Array(10).fill(0));

for (let j = 0; j < 10; j++) {
  dp[1][j] = 1;
}

for (let i = 2; i < 65; i++) {
  for (let j = 0; j < 10; j++) {
    for (let k = j; k < 10; k++) {
      dp[i][j] += dp[i - 1][k];
    }
  }
}

const results = [];

for (let i = 1; i < inputs.length; i++) {
  const n = inputs[i];
  const result = dp[n].reduce((a, b) => a + b);
  results.push(result);
}

console.log(results.join('\n'));
