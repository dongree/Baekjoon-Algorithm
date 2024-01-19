const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const n = +inputs[0];

const dy = [1, 0, -1, 0];
const dx = [0, 1, 0, -1];

const isVisited = Array(n)
  .fill()
  .map(() => Array(n).fill(false));

const miro = [];

for (let i = 1; i <= n; i++) {
  miro.push(inputs[i].split('').map(Number));
}

const q = [[0, 0, 0]];
isVisited[0][0] = true;

while (q.length !== 0) {
  const [y, x, cnt] = q.shift();

  if (y === n - 1 && x === n - 1) {
    console.log(cnt);
    break;
  }

  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];
    if (inRange(ny, nx) && !isVisited[ny][nx]) {
      isVisited[ny][nx] = true;

      if (miro[ny][nx] === 1) {
        q.unshift([ny, nx, cnt]);
      } else {
        q.push([ny, nx, cnt + 1]);
      }
    }
  }
}
function inRange(y, x) {
  return 0 <= y && y < n && 0 <= x && x < n;
}
