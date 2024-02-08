const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const dy = [1, 0, -1, 0];
const dx = [0, 1, 0, -1];

const [N, M] = inputs[0].split(' ').map(Number);
const arr = [];
let answer = 0;

for (let i = 1; i <= N; i++) {
  const subArr = inputs[i].split(' ').map(Number);
  arr.push(subArr);
}

while (true) {
  const melting = Array(N)
    .fill()
    .map(() => Array(M).fill(0));
  const isVisited = Array(N)
    .fill()
    .map(() => Array(M).fill(false));

  answer++;

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (arr[i][j] != 0) {
        let cnt = 0;
        for (let d = 0; d < 4; d++) {
          let ny = i + dy[d];
          let nx = j + dx[d];
          if (arr[ny][nx] === 0) cnt++;
        }
        melting[i][j] = cnt;
      }
    }
  }

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (arr[i][j] !== 0) {
        arr[i][j] =
          arr[i][j] - melting[i][j] < 0 ? 0 : arr[i][j] - melting[i][j];
      }
    }
  }

  let cnt = 0;
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (arr[i][j] !== 0 && !isVisited[i][j]) {
        dfs(i, j);
        cnt++;
      }
    }
  }

  if (cnt >= 2) break;
  else if (cnt === 0) {
    answer = 0;
    break;
  }

  function dfs(y, x) {
    for (let i = 0; i < 4; i++) {
      let ny = y + dy[i];
      let nx = x + dx[i];
      if (inRange(ny, nx) && arr[ny][nx] !== 0 && !isVisited[ny][nx]) {
        isVisited[ny][nx] = true;
        dfs(ny, nx);
      }
    }
  }
}

console.log(answer);

function inRange(y, x) {
  return 0 <= y && y < N && 0 <= x && x < M;
}
