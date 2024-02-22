const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);
const [y1, x1, y2, x2] = inputs[1].split(' ').map(Number);

const dy = [1, 0, -1, 0];
const dx = [0, 1, 0, -1];

const arr = [];
for (let i = 2; i <= N + 1; i++) {
  const subArr = inputs[i].split('');
  arr.push(subArr);
}

let ans = 1;
while (!bfs()) ans++;
console.log(ans);

function bfs() {
  const isVisited = Array(N)
    .fill()
    .map(() => Array(M).fill(false));

  const q = [[y1 - 1, x1 - 1]];
  isVisited[y1 - 1][x1 - 1] = true;

  while (q.length !== 0) {
    const [y, x] = q.shift();

    if (arr[y][x] === '#') {
      return true;
    }

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];

      if (inRange(ny, nx) && !isVisited[ny][nx]) {
        isVisited[ny][nx] = true;
        if (arr[ny][nx] === '1') arr[ny][nx] = '0';
        else q.push([ny, nx]);
      }
    }
  }
  return false;
}

function inRange(y, x) {
  return 0 <= y && y < N && 0 <= x && x < M;
}
