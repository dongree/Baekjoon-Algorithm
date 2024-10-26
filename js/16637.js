const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const s = inputs[1].split('');
const operators = s.filter((_, idx) => idx % 2 === 1);
const operands = s.filter((_, idx) => idx % 2 === 0).map(Number);

const n = Math.floor(N / 2);

const arr = [];
const isVisited = Array(n).fill(false);
let result = -Infinity;

dfs(0);
console.log(result);

function dfs(idx) {
  calc();

  for (let i = idx; i < n; i++) {
    if (isVisited[i]) continue;
    isVisited[i] = true;
    arr.push(i);
    dfs(i + 2);
    arr.pop();
    isVisited[i] = false;
  }
}

function calc() {
  const copyOperators = [...operators];
  const copyOperands = [...operands];

  for (let i = arr.length - 1; i >= 0; i--) {
    const loc = arr[i];
    const operator = copyOperators[loc];

    let res;
    if (operator === '+') {
      res = copyOperands[loc] + copyOperands[loc + 1];
    } else if (operator === '-') {
      res = copyOperands[loc] - copyOperands[loc + 1];
    } else if (operator === '*') {
      res = copyOperands[loc] * copyOperands[loc + 1];
    }

    copyOperators.splice(loc, 1);
    copyOperands.splice(loc, 2, res);
  }

  let k = copyOperands[0];

  for (let i = 0; i < copyOperators.length; i++) {
    const operator = copyOperators[i];

    if (operator === '+') {
      k += copyOperands[i + 1];
    } else if (operator === '-') {
      k -= copyOperands[i + 1];
    } else if (operator === '*') {
      k *= copyOperands[i + 1];
    }
  }

  result = Math.max(k, result);
}
