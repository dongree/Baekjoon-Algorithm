const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const board = [];

for (let i = 1; i <= N; i++) {
  board.push(inputs[i].split('').map(Number));
}

console.log(compression(0, 0, N));

function compression(y, x, n) {
  let zeroCnt = 0;
  let oneCnt = 0;
  for (let i = y; i < y + n; i++) {
    for (let j = x; j < x + n; j++) {
      if (board[i][j] === 0) zeroCnt++;
      else oneCnt++;
    }
  }

  if (zeroCnt === n * n) return '0';
  if (oneCnt === n * n) return '1';

  const hn = Math.floor(n / 2);

  return (
    '(' +
    compression(y, x, hn) +
    compression(y, x + hn, hn) +
    compression(y + hn, x, hn) +
    compression(y + hn, x + hn, hn) +
    ')'
  );
}
