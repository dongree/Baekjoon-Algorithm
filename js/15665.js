const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);
const arr = [...new Set(inputs[1].split(' ').map(Number))].sort((a, b) => a - b);

const result = [];
const temp = [];

dfs(0);

console.log(result.join('\n'));

function dfs(idx) {
  if (temp.length === M) {
    result.push(temp.join(' '));
    return;
  }

  for (let i = 0; i < arr.length; i++) {
    temp.push(arr[i]);
    dfs(idx + 1);
    temp.pop();
  }
}
