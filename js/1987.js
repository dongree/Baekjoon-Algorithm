const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const dy = [1, 0, -1, 0];
const dx = [0, 1, 0, -1];

const [r, c] = inputs[0].split(' ').map(Number);
const board = [];
const visited = Array(26).fill(false);

for (let i = 1; i <= r; i++) {
  board.push(inputs[i].split(''));
}

let answer = 1;
visited[board[0][0].charCodeAt() - 65] = true;

dfs(0, 0, 1);

console.log(answer);

function dfs(y, x, cnt) {
  if (cnt > answer) answer = cnt;
  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];
    if (inRange(ny, nx) && !visited[board[ny][nx].charCodeAt() - 65]) {
      visited[board[ny][nx].charCodeAt() - 65] = true;
      dfs(ny, nx, cnt + 1);
      visited[board[ny][nx].charCodeAt() - 65] = false;
    }
  }
}

function inRange(y, x) {
  return 0 <= y && y < r && 0 <= x && x < c;
}
