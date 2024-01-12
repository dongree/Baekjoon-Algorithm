const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const dy = [0, 1, 0, -1];
const dx = [1, 0, -1, 0];

const [n, m] = inputs[0].split(' ').map(Number);
const map = [];
for (let i = 1; i <= n; i++) {
  const subArr = inputs[i].split(' ').map(Number);
  map.push(subArr);
}
const answer = map.map((subArr) =>
  subArr.map((el) => {
    if (el !== 0) return -1;
    else return 0;
  })
);

const q = [];

outer: for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (map[i][j] === 2) {
      q.push([i, j]);
      answer[i][j] = 0;
      break outer;
    }
  }
}

while (q.length !== 0) {
  const [y, x] = q.shift();
  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];
    if (inRange(ny, nx) && answer[ny][nx] === -1) {
      q.push([ny, nx]);
      answer[ny][nx] = answer[y][x] + 1;
    }
  }
}

console.log(answer.map((subArr) => subArr.join(' ')).join('\n'));

function inRange(y, x) {
  return 0 <= y && y < n && 0 <= x && x < m;
}
