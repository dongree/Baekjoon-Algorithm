const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const MAX = 101;

const N = +inputs[0];
const isDotted = Array(MAX)
  .fill()
  .map(() => Array(MAX).fill(false));

const dy = [0, -1, 0, 1];
const dx = [1, 0, -1, 0];

for (let i = 1; i <= N; i++) {
  const direction = [];
  let [x, y, d, g] = inputs[i].split(' ').map(Number);

  isDotted[y][x] = true;

  // 0 generation
  y = y + dy[d];
  x = x + dx[d];

  isDotted[y][x] = true;
  direction.push(d);

  while (g--) {
    makeDragonCurve();
  }

  function makeDragonCurve() {
    for (let i = direction.length - 1; i >= 0; i--) {
      const nd = (direction[i] + 1) % 4;
      y = y + dy[nd];
      x = x + dx[nd];
      isDotted[y][x] = true;
      direction.push(nd);
    }
  }
}

let cnt = 0;

for (let i = 0; i < MAX - 1; i++) {
  for (let j = 0; j < MAX - 1; j++) {
    if (
      isDotted[i][j] &&
      isDotted[i][j + 1] &&
      isDotted[i + 1][j] &&
      isDotted[i + 1][j + 1]
    ) {
      cnt++;
    }
  }
}

console.log(cnt);
