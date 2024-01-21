const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);
const campus = [];
const dy = [1, 0, -1, 0];
const dx = [0, 1, 0, -1];
const isVisited = Array(N)
  .fill()
  .map(() => Array(M).fill(false));
let answer = 0;

for (let i = 1; i <= N; i++) {
  const subArr = inputs[i].split('');
  campus.push(subArr);
}

for (let i = 0; i < N; i++) {
  for (let j = 0; j < M; j++) {
    if (campus[i][j] === 'I') {
      isVisited[i][j] = true;
      dfs(i, j);
    }
  }
}

console.log(answer ? answer : 'TT');

function dfs(y, x) {
  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    if (inRange(ny, nx) && !isVisited[ny][nx] && campus[ny][nx] !== 'X') {
      if (campus[ny][nx] === 'P') answer++;
      isVisited[ny][nx] = true;
      dfs(ny, nx);
    }
  }
}

function inRange(y, x) {
  return 0 <= y && y < N && 0 <= x && x < M;
}
