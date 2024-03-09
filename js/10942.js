const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const answer = [];

let idx = 0;
const getLine = () => inputs[idx++];

const [N] = getLine();
const arr = [0, ...getLine()];

const dp = Array(N + 1)
  .fill()
  .map(() => Array(N + 1).fill(0));

let [M] = getLine();
for (let i = 1; i <= N; i++) {
  dp[i][i] = 1;
  if (i + 1 <= N) {
    if (arr[i] === arr[i + 1]) dp[i][i + 1] = 1;
  }
}

for (let diff = 2; diff <= N; diff++) {
  for (let i = 1; i + diff <= N; i++) {
    const j = i + diff;
    if (dp[i + 1][j - 1] && arr[i] === arr[j]) dp[i][j] = 1;
  }
}

while (M--) {
  const [i, j] = getLine();
  answer.push(dp[i][j]);
}

console.log(answer.join('\n'));
