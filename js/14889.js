const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];

const check = Array(n).fill(0);
const arr = [];
let result = Infinity;

for (let i = 1; i <= n; i++) {
  const subArr = inputs[i].split(' ').map(Number);
  arr.push(subArr);
}

dfs(0, 0);
console.log(result);

function dfs(cnt, idx) {
  if (cnt === n / 2) {
    const selected = [];
    const unselected = [];
    let selectedScore = 0;
    let unselectedScore = 0;

    for (let i = 0; i < n; i++) {
      if (check[i]) selected.push(i);
      else unselected.push(i);
    }

    for (let i = 0; i < n / 2; i++) {
      for (let j = 0; j < n / 2; j++) {
        if (i !== j) {
          selectedScore += arr[selected[i]][selected[j]];
          unselectedScore += arr[unselected[i]][unselected[j]];
        }
      }
    }

    if (Math.abs(selectedScore - unselectedScore) < result)
      result = Math.abs(selectedScore - unselectedScore);
    return;
  }
  for (let i = idx; i < n; i++) {
    check[i] = 1;
    dfs(cnt + 1, i + 1);
    check[i] = 0;
  }
}
