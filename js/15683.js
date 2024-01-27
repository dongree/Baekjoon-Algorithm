const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);

const dy = [0, 1, 0, -1];
const dx = [1, 0, -1, 0];

const arr = [];
const cctv = [];
let answer = 100;

for (let i = 1; i <= N; i++) {
  const subArr = inputs[i].split(' ').map((el, j) => {
    if (1 <= el && el <= 5) cctv.push([i - 1, j]);
    return +el;
  });
  arr.push(subArr);
}

dfs(0);

console.log(answer);

function dfs(idx) {
  if (idx === cctv.length) {
    let cnt = 0;
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < M; j++) {
        if (arr[i][j] === 0) cnt++;
      }
    }

    answer = Math.min(answer, cnt);
    return;
  }

  const y = cctv[idx][0];
  const x = cctv[idx][1];

  const temp = Array(N)
    .fill()
    .map(() => Array(M).fill(0));

  for (let dir = 0; dir < 4; dir++) {
    temp.forEach((subArr, i) =>
      subArr.forEach((_, j) => (temp[i][j] = arr[i][j]))
    );

    switch (arr[y][x]) {
      case 1: {
        check(y, x, dir);
        break;
      }
      case 2: {
        check(y, x, dir);
        check(y, x, dir + 2);
        break;
      }
      case 3: {
        check(y, x, dir);
        check(y, x, dir + 1);
        break;
      }
      case 4: {
        check(y, x, dir);
        check(y, x, dir + 1);
        check(y, x, dir + 2);
        break;
      }
      case 5: {
        check(y, x, dir);
        check(y, x, dir + 1);
        check(y, x, dir + 2);
        check(y, x, dir + 3);
        break;
      }
      default:
        break;
    }

    dfs(idx + 1);

    arr.forEach((subArr, i) =>
      subArr.forEach((_, j) => (arr[i][j] = temp[i][j]))
    );
  }
}

function check(y, x, dir) {
  dir %= 4;
  while (true) {
    const ny = y + dy[dir];
    const nx = x + dx[dir];
    y = ny;
    x = nx;
    if (!(0 <= ny && ny < N && 0 <= nx && nx < M)) return;
    if (arr[ny][nx] === 6) return;
    if (arr[ny][nx] !== 0) continue;
    arr[ny][nx] = -1;
  }
}
