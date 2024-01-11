const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m, b] = inputs[0].split(' ').map(Number);
const arr = [];
for (let i = 1; i <= n; i++) {
  arr.push(inputs[i].split(' ').map(Number));
}

let answerTime = Infinity;
let answerHeight = -1;

for (let h = 0; h <= 256; h++) {
  let createCnt = 0;
  let removeCnt = 0;

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      let gap = arr[i][j] - h;
      if (gap < 0) createCnt -= gap;
      else removeCnt += gap;
    }
  }
  if (createCnt - removeCnt <= b) {
    let time = 2 * removeCnt + createCnt;
    if (answerTime >= time) {
      answerTime = time;
      answerHeight = h;
    }
  }
}

console.log(answerTime, answerHeight);
