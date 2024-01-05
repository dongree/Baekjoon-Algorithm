const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, s] = inputs[0].split(' ').map(Number);
const arr = inputs[1].split(' ').map(Number);

let answer = 0;

dfs(0, 0);
console.log(answer);

function dfs(sum, idx) {
  if (idx !== 0 && sum === s) answer++;
  for (let i = idx; i < n; i++) {
    sum += arr[i];
    dfs(sum, i + 1);
    sum -= arr[i];
  }
}
