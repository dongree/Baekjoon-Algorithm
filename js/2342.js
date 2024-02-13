const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

const arr = inputs.slice(0, inputs.length - 1);
const n = arr.length;
const dp = Array(n)
  .fill()
  .map(() =>
    Array(5)
      .fill()
      .map(() => Array(5).fill(-1))
  );

console.log(dfs(0, 0, 0));

function dfs(l, r, idx) {
  if (idx === n) return 0;
  if (dp[idx][l][r] !== -1) return dp[idx][l][r];

  const left = dfs(arr[idx], r, idx + 1) + calc(l, arr[idx]);
  const right = dfs(l, arr[idx], idx + 1) + calc(r, arr[idx]);

  return (dp[idx][l][r] = Math.min(left, right));
}

function calc(a, target) {
  if (a === target) return 1;
  else if (a === 0) return 2;
  else if (Math.abs(a - target) === 2) return 4;
  else return 3;
}
