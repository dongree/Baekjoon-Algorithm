const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m] = inputs[0].split(' ').map(Number);

const arr = [];
const badCombi = Array(n + 1)
  .fill()
  .map(() => Array(n + 1).fill(false));

let answer = 0;
for (let i = 1; i <= m; i++) {
  const [a, b] = inputs[i].split(' ').map(Number);
  badCombi[a][b] = true;
  badCombi[b][a] = true;
}

dfs(1, 0);
console.log(answer);

function dfs(idx, cnt) {
  if (cnt === 3) {
    answer++;
    return;
  }
  for (let i = idx; i <= n; i++) {
    if (!arr.some((el) => badCombi[i][el])) {
      arr.push(i);
      dfs(i + 1, cnt + 1);
      arr.pop();
    }
  }
}
