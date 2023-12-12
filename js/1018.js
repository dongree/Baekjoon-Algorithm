const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().split('\n');
const [m, n] = inputs[0].split(' ').map(Number);

const board = [];
let result = m * n;

for (let i = 1; i <= m; i++) {
  board.push(inputs[i]);
}

for (let i = 0; i <= m - 8; i++) {
  for (j = 0; j <= n - 8; j++) {
    const a = checkBoard(i, j);
    result = Math.min(result, a, 64 - a);
  }
}

function checkBoard(y, x) {
  let cnt = 0;
  for (let i = y; i < y + 8; i++) {
    for (let j = x; j < x + 8; j++) {
      if (
        ((i + j) % 2 === 0 && board[i][j] === 'B') ||
        ((i + j) % 2 === 1 && board[i][j] === 'W')
      )
        cnt++;
    }
  }
  return cnt;
}

console.log(result);
