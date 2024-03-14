const fs = require('fs');

const board = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(''));

const isVisited = Array(5)
  .fill()
  .map(() => Array(5).fill(false));

const dy = [0, 1, 0, -1];
const dx = [1, 0, -1, 0];

let answer = 0;

dfs(0, 0, 0);

console.log(answer);

function dfs(cur, sCnt, yCnt) {
  if (yCnt >= 4) {
    return;
  }

  if (sCnt + yCnt === 7) {
    if (isConnexted()) answer++;
    return;
  }

  for (let i = cur; i < 25; i++) {
    const y = Math.floor(i / 5);
    const x = i % 5;
    if (!isVisited[y][x]) {
      isVisited[y][x] = true;
      if (board[y][x] === 'S') dfs(i + 1, sCnt + 1, yCnt);
      else dfs(i + 1, sCnt, yCnt + 1);
      isVisited[y][x] = false;
    }
  }
}

function isConnexted() {
  let sy, sx;
  let flag = false;
  const subVisited = Array(5)
    .fill()
    .map(() => Array(5).fill(false));

  for (let i = 0; i < 5; i++) {
    if (flag) break;
    for (let j = 0; j < 5; j++) {
      if (isVisited[i][j]) {
        sy = i;
        sx = j;
        flag = true;
        break;
      }
    }
  }
  const q = [[sy, sx]];
  subVisited[sy][sx] = true;
  let cnt = 1;

  while (q.length !== 0) {
    const [y, x] = q.shift();

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (
        0 <= ny &&
        ny < 5 &&
        0 <= nx &&
        nx < 5 &&
        isVisited[ny][nx] &&
        !subVisited[ny][nx]
      ) {
        subVisited[ny][nx] = true;
        q.push([ny, nx]);
        cnt++;
      }
    }
  }
  return cnt === 7;
}
