const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];

const arr = [];
const answerArr = [];

for (let i = 1; i <= N; i++) {
  const subArr = inputs[i].split(' ').map(Number);
  arr.push([...subArr]);
  answerArr.push([...subArr]);
}

const isImpossible = floyd();

if (isImpossible) console.log(-1);
else {
  let answer = 0;
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      answer += answerArr[i][j];
    }
  }
  console.log(answer / 2);
}

function floyd() {
  for (let k = 0; k < N; k++) {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        if (i === k || j === k) continue;
        if (arr[i][j] > arr[i][k] + arr[k][j]) {
          return true;
        }
        if (arr[i][j] === arr[i][k] + arr[k][j]) {
          answerArr[i][j] = 0;
        }
      }
    }
  }
  return false;
}
