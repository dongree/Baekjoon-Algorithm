const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const dy = [0, 1, 0, -1];
const dx = [1, 0, -1, 0];

const [n, m] = inputs[0].split(' ').map(Number);
const map = [];
for (let i = 1; i <= n; i++) {
  const subArr = inputs[i].trim().split(' ').map(Number);
  map.push(subArr);
}
let answer = 0;

dfs(0, -1, 0);
console.log(answer);

function dfs(y, x, cnt) {
  if (cnt === 3) {
    const tempMap = map.map((subArr) => [...subArr]);
    const safeArea = getSafeArea(tempMap);
    answer = Math.max(answer, safeArea);
    return;
  }

  for (let i = y; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (i == y && j <= x) continue;
      if (map[i][j] === 0) {
        map[i][j] = 1;
        dfs(i, j, cnt + 1);
        map[i][j] = 0;
      }
    }
  }
}

function getSafeArea(map) {
  const q = [];
  let idx = 0;

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (map[i][j] === 2) {
        q.push([i, j]);
      }
    }
  }

  while (q.length !== idx) {
    const [y, x] = q[idx++];
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (0 <= ny && ny < n && 0 <= nx && nx < m && map[ny][nx] === 0) {
        map[ny][nx] = 2;
        q.push([ny, nx]);
      }
    }
  }

  return map.flat().filter((el) => el === 0).length;
}
