const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const [N, M] = getLine().split(' ').map(Number);

const board = [];

for (let i = 0; i < N; i++) {
  const arr = getLine().split('');
  board.push(arr);
}

const a = Math.min(N, M);
let l = 1;

for (let k = a; k > 0; k--) {
  let flag = false;
  b: for (let i = 0; i <= N - k; i++) {
    for (let j = 0; j <= M - k; j++) {
      if (
        board[i][j] === board[i][j + k - 1] &&
        board[i][j] === board[i + k - 1][j] &&
        board[i][j] === board[i + k - 1][j + k - 1]
      ) {
        flag = true;
        break b;
      }
    }
  }
  if (flag) {
    l = k;
    break;
  }
}

console.log(l * l);
