const fs = require('fs');

const [n, k, ...arr] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

const isVisited = Array(n).fill(false);
const st = new Set();

dfs(0, '');
console.log(st.size);

function dfs(cnt, s) {
  if (cnt === k) {
    st.add(s);
    return;
  }

  for (let i = 0; i < n; i++) {
    if (!isVisited[i]) {
      isVisited[i] = true;
      dfs(cnt + 1, s + arr[i].toString());
      isVisited[i] = false;
    }
  }
}
