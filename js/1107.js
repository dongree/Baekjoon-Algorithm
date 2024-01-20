const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const M = +inputs[1];
const crushed = Array(10).fill(false);
M !== 0 && inputs[2].split(' ').forEach((e) => (crushed[+e] = true));
let answer = Math.abs(N - 100);

for (let i = 1; i <= 6; i++) {
  dfs(i, 0, 0);
}

console.log(answer);

function dfs(length, cnt, sum) {
  if (length === cnt) {
    answer = Math.min(answer, cnt + Math.abs(N - sum));
    return;
  }
  for (let i = 0; i <= 9; i++) {
    if (!crushed[i]) {
      dfs(length, cnt + 1, sum + 10 ** cnt * i);
    }
  }
}
