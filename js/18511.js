const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, K] = inputs[0].split(' ').map(Number);
const arr = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => b - a);

let temp = [];
let result = 0;

dfs(0);

console.log(result);

function dfs(cnt) {
  const a = +temp.join('');
  if (N >= a && a > result) result = a;

  if (cnt === N.toString().length) return;

  for (let i = 0; i < K; i++) {
    temp.push(arr[i]);
    dfs(cnt + 1);
    temp.pop();
  }
}
