const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = [];

for (let i = 1; i <= N; i++) {
  arr.push(inputs[i].split(''));
}

let result = 0;

for (let i = 0; i < N; i++) {
  let cnt = 0;

  for (let j = 0; j < N; j++) {
    if (i === j) continue;
    if (arr[i][j] === 'Y' && arr[j][i] === 'Y') {
      cnt++;
      continue;
    }
    for (let k = 0; k < N; k++) {
      if (i === k || i === j) continue;
      if (arr[i][k] === 'Y' && arr[j][k] === 'Y') {
        cnt++;
        break;
      }
    }
  }
  result = Math.max(result, cnt);
}

console.log(result);
