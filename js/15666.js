const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m] = inputs[0].split(' ').map(Number);

const arr = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);

const subArr = [];
const answer = [];

dfs(0, 0);

console.log([...new Set(answer)].join('\n'));

function dfs(idx, cnt) {
  if (cnt === m) {
    answer.push(subArr.join(' '));
    return;
  }

  for (let i = idx; i < n; i++) {
    subArr.push(arr[i]);
    dfs(i, cnt + 1);
    subArr.pop();
  }
}
