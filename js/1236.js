const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const [N, M] = getLine().split(' ').map(Number);

const arr = [];

for (let i = 0; i < N; i++) {
  const subArr = getLine().split('');
  arr.push(subArr);
}

let rowCnt = 0;
let colCnt = 0;

for (let i = 0; i < N; i++) {
  let cnt = 0;
  for (let j = 0; j < M; j++) {
    if (arr[i][j] === 'X') cnt++;
  }
  if (cnt === 0) rowCnt++;
}

for (let i = 0; i < M; i++) {
  let cnt = 0;
  for (let j = 0; j < N; j++) {
    if (arr[j][i] === 'X') cnt++;
  }
  if (cnt === 0) colCnt++;
}

console.log(Math.max(rowCnt, colCnt));
