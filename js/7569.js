const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [m, n, h] = inputs[0].split(' ').map(Number);

const storage = [];

for (let i = 0; i < h; i++) {
  const arr = [];
  for (let j = n * i + 1; j <= n * (i + 1); j++) {
    arr.push(inputs[j].split(' ').map(Number));
  }
  storage.push(arr);
}

const dz = [0, 0, 0, 0, 1, -1];
const dy = [-1, 0, 1, 0, 0, 0];
const dx = [0, 1, 0, -1, 0, 0];

const q = [];

for (let i = 0; i < h; i++) {
  for (let j = 0; j < n; j++) {
    for (let k = 0; k < m; k++) {
      if (storage[i][j][k] === 1) q.push([i, j, k, 0]);
    }
  }
}

let idx = 0;

while (q.length !== idx) {
  const [z, y, x, day] = q[idx++];
  for (let i = 0; i < 6; i++) {
    const nz = z + dz[i];
    const ny = y + dy[i];
    const nx = x + dx[i];
    if (inRange(nz, ny, nx) && storage[nz][ny][nx] === 0) {
      storage[nz][ny][nx] = 1;
      q.push([nz, ny, nx, day + 1]);
    }
  }
}

console.log(getResult());

function getResult() {
  for (let i = 0; i < h; i++) {
    for (let j = 0; j < n; j++) {
      for (let k = 0; k < m; k++) {
        if (storage[i][j][k] === 0) return -1;
      }
    }
  }
  return q[q.length - 1][3];
}

function inRange(z, y, x) {
  return 0 <= z && z < h && 0 <= y && y < n && 0 <= x && x < m;
}
