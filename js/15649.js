const fs = require('fs');

const [n, m] = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

const isVisited = Array(n + 1).fill(false);
const arr = [];
let result = '';

dfs(0);
console.log(result);

function dfs(cnt) {
  if (cnt === m) {
    result += `${arr.join(' ')}\n`;
    return;
  }
  for (let i = 1; i <= n; i++) {
    if (!isVisited[i]) {
      isVisited[i] = true;
      arr.push(i);
      dfs(cnt + 1);
      arr.pop();
      isVisited[i] = false;
    }
  }
}
