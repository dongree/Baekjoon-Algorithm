const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m] = inputs[0].split(' ').map(Number);
const visited = Array(n)
  .fill()
  .map(() =>
    Array(m)
      .fill()
      .map(() => Array(2).fill(0))
  );
const map = [];
const dy = [0, -1, 0, 1];
const dx = [1, 0, -1, 0];

for (let i = 1; i <= n; i++) {
  map.push(inputs[i].split('').map(Number));
}

const q = [[0, 0, 0]];
visited[0][0][0] = 1;
let idx = 0;
let answer = -1;

while (q.length !== idx) {
  const [y, x, isBreak] = q[idx++];
  if (y === n - 1 && x === m - 1) {
    answer = visited[y][x][isBreak];
    break;
  }

  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];
    if (inRange(ny, nx)) {
      if (map[ny][nx] === 0 && visited[ny][nx][isBreak] === 0) {
        visited[ny][nx][isBreak] = visited[y][x][isBreak] + 1;
        q.push([ny, nx, isBreak]);
      } else if (map[ny][nx] === 1 && isBreak === 0) {
        visited[ny][nx][1] = visited[y][x][0] + 1;
        q.push([ny, nx, 1]);
      }
    }
  }
}

console.log(answer);

function inRange(y, x) {
  return 0 <= y && y < n && 0 <= x && x < m;
}
