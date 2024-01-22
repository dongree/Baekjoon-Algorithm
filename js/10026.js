const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];

const picture = [];

const isVisited = Array(N)
  .fill()
  .map(() => Array(N).fill(false));
const isVisited2 = Array(N)
  .fill()
  .map(() => Array(N).fill(false));

const dy = [1, 0, -1, 0];
const dx = [0, 1, 0, -1];

for (let i = 1; i <= N; i++) {
  const subArr = inputs[i].split('');
  picture.push(subArr);
}

let cnt = 0;
let cnt2 = 0;

for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    if (!isVisited[i][j]) {
      isVisited[i][j] = true;
      dfs(i, j, false);
      cnt += 1;
    }
    if (!isVisited2[i][j]) {
      isVisited2[i][j] = true;
      dfs(i, j, true);
      cnt2 += 1;
    }
  }
}

console.log(cnt, cnt2);

function dfs(y, x, isRG) {
  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    if (
      inRange(ny, nx) &&
      (isRG ? !isVisited2[ny][nx] : !isVisited[ny][nx]) &&
      (isRG
        ? ((picture[y][x] === 'R' || picture[y][x] === 'G') &&
            picture[ny][nx] !== 'B') ||
          (picture[y][x] === 'B' && picture[ny][nx] === 'B')
        : picture[y][x] === picture[ny][nx])
    ) {
      isRG ? (isVisited2[ny][nx] = true) : (isVisited[ny][nx] = true);
      dfs(ny, nx, isRG);
    }
  }
}

function inRange(y, x) {
  return 0 <= y && y < N && 0 <= x && x < N;
}
