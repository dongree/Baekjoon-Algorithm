const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const dy = [1, 0, -1, 0];
const dx = [0, 1, 0, -1];

const A = [];
const [N, L, R] = inputs[0].split(' ').map(Number);
const unionFlag = Array(N)
  .fill()
  .map(() => Array(N).fill(0));
const unionMeanPerContury = Array(N * N + 1).fill(0);
let unionPeopleNum;
let unionNum;
let u = 1;
let day = -1;

for (let i = 1; i <= N; i++) {
  const subArr = inputs[i].split(' ').map(Number);
  A.push(subArr);
}

while (u <= N * N) {
  init();

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (unionFlag[i][j] === 0) {
        unionPeopleNum = A[i][j];
        unionNum = 1;
        unionFlag[i][j] = u;
        dfs(i, j);
        unionMeanPerContury[u] = Math.floor(unionPeopleNum / unionNum);
        u++;
      }
    }
  }

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      A[i][j] = unionMeanPerContury[unionFlag[i][j]];
    }
  }

  day++;
}

console.log(day);

function dfs(y, x) {
  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    if (inRange(ny, nx) && unionFlag[ny][nx] === 0) {
      const d = Math.abs(A[y][x] - A[ny][nx]);
      if (!(L <= d && d <= R)) continue;
      unionFlag[ny][nx] = u;
      unionPeopleNum += A[ny][nx];
      unionNum++;
      dfs(ny, nx);
    }
  }
}

function inRange(y, x) {
  return 0 <= y && y < N && 0 <= x && x < N;
}

function init() {
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      unionFlag[i][j] = 0;
    }
  }
  for (let i = 0; i <= N * N; i++) {
    unionMeanPerContury[i] = 0;
  }
  u = 1;
}
