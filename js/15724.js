const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const [N, M] = getLine().split(' ').map(Number);
const board = [];
const ps = Array(N + 1)
  .fill()
  .map(() => Array(M + 1).fill(0));

for (let i = 0; i < N; i++) {
  board.push(getLine().split(' ').map(Number));
}

for (let i = 1; i <= N; i++) {
  for (let j = 1; j <= M; j++) {
    ps[i][j] =
      board[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
  }
}

const K = +getLine();

const ans = [];

for (let i = 0; i < K; i++) {
  const [x1, y1, x2, y2] = getLine().split(' ').map(Number);

  ans.push(ps[x2][y2] - ps[x2][y1 - 1] - ps[x1 - 1][y2] + ps[x1 - 1][y1 - 1]);
}

console.log(ans.join('\n'));
