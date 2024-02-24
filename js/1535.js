// brute force

// const fs = require('fs');

// const inputs = fs.readFileSync('example.txt').toString().split('\n');

// const N = +inputs[0];
// const L = inputs[1].split(' ').map(Number);
// const J = inputs[2].split(' ').map(Number);

// let ans = 0;

// dfs(100, 0, 0);
// console.log(ans);

// function dfs(life, happy, idx) {
//   ans = Math.max(ans, happy);

//   if (idx === N) {
//     return;
//   }
//   for (let i = idx; i < N; i++) {
//     if (life - L[i] > 0) {
//       dfs(life - L[i], happy + J[i], i + 1);
//     }
//   }
// }

// dp
const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().split('\n');

const N = +inputs[0];
const L = [0, ...inputs[1].split(' ').map(Number)];
const J = [0, ...inputs[2].split(' ').map(Number)];

const dp = Array(N + 1)
  .fill()
  .map(() => Array(101).fill(0));

for (let i = 1; i <= N; i++) {
  for (let j = 1; j <= 100; j++) {
    if (L[i] < j) {
      dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - L[i]] + J[i]);
    } else {
      dp[i][j] = dp[i - 1][j];
    }
  }
}

console.log(dp[N][100]);
