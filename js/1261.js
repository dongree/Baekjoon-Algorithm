// 길이가 3인 배열을 q에 담기
const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const dy = [1, 0, -1, 0];
const dx = [0, 1, 0, -1];

const [m, n] = inputs[0].split(' ').map(Number);
const miro = [];
for (let i = 1; i <= n; i++) {
  const subArr = inputs[i].split('').map(Number);
  miro.push(subArr);
}

const isVisited = Array(n)
  .fill()
  .map(() => Array(m).fill(false));

const dq = [[0, 0, 0]];
isVisited[0][0] = true;
while (dq.length !== 0) {
  const [y, x, cnt] = dq.shift();

  if (y === n - 1 && x === m - 1) {
    console.log(cnt);
    break;
  }

  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];
    if (inRange(ny, nx) && !isVisited[ny][nx]) {
      isVisited[ny][nx] = true;
      if (miro[ny][nx] === 0) dq.unshift([ny, nx, cnt]);
      else dq.push([ny, nx, cnt + 1]);
    }
  }
}

function inRange(y, x) {
  return 0 <= y && y < n && 0 <= x && x < m;
}

// crushed 배열 사용
// const fs = require('fs');

// const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

// const dy = [1, 0, -1, 0];
// const dx = [0, 1, 0, -1];

// const [m, n] = inputs[0].split(' ').map(Number);
// const miro = [];
// for (let i = 1; i <= n; i++) {
//   const subArr = inputs[i].split('').map(Number);
//   miro.push(subArr);
// }

// const isVisited = Array(n)
//   .fill()
//   .map(() => Array(m).fill(false));

// const crushed = Array(n)
//   .fill()
//   .map(() => Array(m).fill(0));

// const dq = [[0, 0]];
// isVisited[0][0] = true;
// while (dq.length !== 0) {
//   const [y, x] = dq.shift();

//   if (y === n - 1 && x === m - 1) {
//     console.log(crushed[y][x]);
//     break;
//   }

//   for (let i = 0; i < 4; i++) {
//     const ny = y + dy[i];
//     const nx = x + dx[i];
//     if (inRange(ny, nx) && !isVisited[ny][nx]) {
//       isVisited[ny][nx] = true;
//       if (miro[ny][nx] === 0) dq.unshift([ny, nx]);
//       else dq.push([ny, nx]);
//       crushed[ny][nx] = crushed[y][x] + miro[ny][nx];
//     }
//   }
// }

// function inRange(y, x) {
//   return 0 <= y && y < n && 0 <= x && x < m;
// }
