const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];
const arr = [];

const [N, M] = getLine().split(' ').map(Number);
let ans = 0;

for (let i = 0; i < N; i++) {
  arr.push(getLine());
}

const K = +getLine();

for (let i = 0; i < N; i++) {
  let zeroCnt = 0;
  for (let j = 0; j < M; j++) {
    if (arr[i][j] === '0') zeroCnt++;
  }

  if (zeroCnt <= K && zeroCnt % 2 === K % 2) {
    let cnt = 0;
    for (let y = 0; y < N; y++) {
      if (arr[i] === arr[y]) cnt++;
    }
    ans = Math.max(ans, cnt);
  }
}

console.log(ans);
