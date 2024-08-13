const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const N = +getLine();
const difficulty = getLine().split(' ').map(Number);

const dp = Array(N + 1).fill(0);
for (let i = 1; i < difficulty.length; i++) {
  if (difficulty[i - 1] > difficulty[i]) {
    dp[i] = 1;
  }
}

for (let i = 1; i < dp.length; i++) {
  dp[i] += dp[i - 1];
}
const Q = +getLine();

const result = [];

for (let i = 0; i < Q; i++) {
  const [x, y] = getLine().split(' ').map(Number);
  result.push(dp[y - 1] - dp[x - 1]);
}

console.log(result.join('\n'));
