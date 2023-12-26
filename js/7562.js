const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const t = +inputs[0];
const dy = [-2, -1, 1, 2, 2, 1, -1, -2];
const dx = [1, 2, 2, 1, -1, -2, -2, -1];
const answer = [];

for (let i = 0; i < t; i++) {
  const n = +inputs[3 * i + 1];
  const startLoc = inputs[3 * i + 2].split(' ').map(Number);
  const [targetY, targetX] = inputs[3 * i + 3].split(' ').map(Number);
  const visited = Array(n)
    .fill()
    .map(() => Array(n).fill(false));

  const q = [[...startLoc, 0]];
  let idx = 0;

  while (q.length !== 0) {
    const [y, x, cnt] = q[idx++];
    if (y === targetY && x === targetX) {
      answer.push(cnt);
      break;
    }
    for (let i = 0; i < 8; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (inRange(ny, nx) && !visited[ny][nx]) {
        visited[ny][nx] = true;
        q.push([ny, nx, cnt + 1]);
      }
    }
  }

  function inRange(y, x) {
    return 0 <= y && y < n && 0 <= x && x < n;
  }
}

console.log(answer.join('\n'));
