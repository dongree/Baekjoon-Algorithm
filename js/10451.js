const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

let T = +getLine();
const ans = [];

while (T--) {
  const N = +getLine();

  const isVisited = Array(N + 1).fill(false);
  let arr = getLine().split(' ').map(Number);
  arr = [0, ...arr];
  let cnt = 0;

  for (let i = 1; i <= N; i++) {
    if (!isVisited[i]) {
      dfs(i);
      cnt++;
    }
  }

  ans.push(cnt);

  function dfs(n) {
    const stack = [n];

    while (stack.length) {
      const a = stack.pop();
      isVisited[a] = true;
      if (!isVisited[arr[a]]) stack.push(arr[a]);
    }
  }
}

console.log(ans.join('\n'));
