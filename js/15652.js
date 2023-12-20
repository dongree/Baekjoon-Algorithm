const fs = require('fs');

const [n, m] = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

const arr = [];
let result = '';

dfs(0, 1);
console.log(result);

function dfs(cnt, num) {
  if (cnt === m) {
    result += `${arr.join(' ')}\n`;
    return;
  }
  for (let i = num; i <= n; i++) {
    arr.push(i);
    dfs(cnt + 1, i);
    arr.pop();
  }
}
