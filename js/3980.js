const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

let T = +getLine();

const result = [];

while (T--) {
  const arr = [];
  const isVisited = Array(11).fill(false);
  for (let i = 0; i < 11; i++) {
    arr.push(getLine().split(' ').map(Number));
  }

  let maxScore = 0;

  dfs(0, 0);
  result.push(maxScore);

  function dfs(idx, score) {
    if (idx === 11) {
      maxScore = Math.max(maxScore, score);
      return;
    }

    for (let i = 0; i < 11; i++) {
      if (arr[idx][i] === 0 || isVisited[i]) continue;
      isVisited[i] = true;
      dfs(idx + 1, score + arr[idx][i]);
      isVisited[i] = false;
    }
  }
}

console.log(result.join('\n'));
