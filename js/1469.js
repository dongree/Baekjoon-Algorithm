const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1].split(' ').map(Number);

const newArr = [...arr, ...arr].sort((a, b) => a - b);
const NN = N * 2;

const isVisited = Array(NN).fill(false);
const result = Array(NN).fill(-1);

let flag = false;
dfs(0);

if (!flag) console.log(-1);

function dfs(idx) {
  if (flag) return;

  if (idx === NN) {
    flag = true;
    console.log(result.join(' '));
    return;
  }

  if (result[idx] !== -1) {
    dfs(idx + 1);
    return;
  }

  for (let i = 0; i < NN; i++) {
    if (isVisited[newArr[i]]) continue;

    const nextIdx = idx + newArr[i] + 1;

    if (nextIdx < NN && result[nextIdx] === -1) {
      result[idx] = newArr[i];
      result[nextIdx] = newArr[i];
      isVisited[newArr[i]] = true;
      dfs(idx + 1);
      result[idx] = -1;
      result[nextIdx] = -1;
      isVisited[newArr[i]] = false;
    }
  }
}
