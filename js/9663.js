const fs = require('fs');

const n = +fs.readFileSync('/dev/stdin').toString().trim();

const arr = [];
let cnt = 0;

dfs(0);

console.log(cnt);

function dfs(y) {
  if (arr.length === n) {
    cnt++;
    return;
  }

  for (let i = 0; i < n; i++) {
    if (isOk(y, i)) {
      arr.push([y, i]);
      dfs(y + 1);
      arr.pop();
    }
  }
}

function isOk(y, x) {
  for (let i = 0; i < arr.length; i++) {
    const [a, b] = arr[i];
    if (y === a || x === b || Math.abs(y - a) - Math.abs(x - b) === 0) {
      return false;
    }
  }
  return true;
}
