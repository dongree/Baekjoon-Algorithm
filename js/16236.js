const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const space = [];
let startY, startX;
const isVisited = Array(N)
  .fill()
  .map(() => Array(N).fill(false));
let sharkSize = 2;
let answer = 0;
let cnt = 0;
let eat = false;

const dy = [-1, 0, 1, 0];
const dx = [0, -1, 0, 1];

for (let i = 1; i <= N; i++) {
  const subArr = inputs[i].split(' ').map((e, j) => {
    if (+e === 9) {
      startY = i - 1;
      startX = j;
    }
    return +e;
  });
  space.push(subArr);
}

while (true) {
  init();
  bfs(startY, startX);

  if (eat) {
    cnt++;
    eat = false;
    if (cnt == sharkSize) {
      cnt = 0;
      sharkSize++;
    }
  } else {
    break;
  }
}

console.log(answer);

function init() {
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      isVisited[i][j] = false;
    }
  }
}

function inRange(y, x) {
  return 0 <= y && y < N && 0 <= x && x < N;
}

function bfs(a, b) {
  const q = [];
  space[a][b] = 0;
  isVisited[a][b] = true;
  q.push([a, b, 0]);
  let temp = 0;

  while (q.length !== 0) {
    const [y, x, t] = q.shift();

    if (0 < space[y][x] && space[y][x] < sharkSize && temp === t) {
      if (y < startY || (y === startY && x < startX)) {
        startY = y;
        startX = x;
      }
    }

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (inRange(ny, nx) && !isVisited[ny][nx] && space[ny][nx] <= sharkSize) {
        if (0 < space[ny][nx] && space[ny][nx] < sharkSize && !eat) {
          eat = true;
          startY = ny;
          startX = nx;
          temp = t + 1;
          answer += temp;
        } else {
          isVisited[ny][nx] = true;
          q.push([ny, nx, t + 1]);
        }
      }
    }
  }
}
