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

dfs(0, 1);
console.log(result);

function dfs(cnt, num) {
  if (cnt === m) {
    result += `${arr.join(' ')}\n`;
    return;
  }
  for (let i = num; i <= n; i++) {
    if (!isVisited[i]) {
      isVisited[i] = true;
      arr.push(i);
      dfs(cnt + 1, i + 1);
      arr.pop();
      isVisited[i] = false;
    }
  }
}
