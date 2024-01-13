const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m] = inputs[0].split(' ').map(Number);

const arr = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);

const isVisited = Array(m).map(() => false);
const subArr = [];
const answer = [];

dfs(0);

console.log([...new Set(answer)].join('\n'));

function dfs(cnt) {
  if (cnt === m) {
    answer.push(subArr.join(' '));
    return;
  }

  for (let i = 0; i < n; i++) {
    if (!isVisited[i]) {
      isVisited[i] = true;
      subArr.push(arr[i]);
      dfs(cnt + 1);
      subArr.pop();
      isVisited[i] = false;
    }
  }
}
