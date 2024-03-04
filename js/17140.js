const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [r, c, k] = inputs.shift();

const arr = Array(101)
  .fill()
  .map((_, i) =>
    Array(101)
      .fill()
      .map((_, j) => {
        if (1 <= i && i <= 3 && 1 <= j && j <= 3) return inputs[i - 1][j - 1];
        return 0;
      })
  );

let t = 0;
let row = 3;
let col = 3;
let answer = -1;

while (t <= 100) {
  if (arr[r][c] === k) {
    answer = t;
    break;
  }

  if (row >= col) R();
  else C();

  t++;
}

console.log(answer);

function R() {
  for (let i = 1; i <= row; i++) {
    const temp = Array(101).fill(0);
    let maxNum = 0;
    for (let j = 1; j <= col; j++) {
      const num = arr[i][j];
      maxNum = Math.max(maxNum, num);
      temp[num]++;
    }
    const next = [];
    for (let j = 1; j <= maxNum; j++) {
      if (temp[j] !== 0) {
        next.push([j, temp[j]]);
      }
    }
    next.sort((a, b) => {
      if (a[1] === b[1]) return a[0] - b[0];
      return a[1] - b[1];
    });
    const flated = next.flat();

    if (flated.length > col) col = flated.length;

    for (let j = 1; j <= col; j++) {
      if (flated.length >= j) arr[i][j] = flated[j - 1];
      else arr[i][j] = 0;
    }
  }
}

function C() {
  for (let i = 1; i <= col; i++) {
    const temp = Array(101).fill(0);
    let maxNum = 0;
    for (let j = 1; j <= row; j++) {
      const num = arr[j][i];
      maxNum = Math.max(maxNum, num);
      temp[num]++;
    }
    const next = [];
    for (let j = 1; j <= maxNum; j++) {
      if (temp[j] !== 0) {
        next.push([j, temp[j]]);
      }
    }

    next.sort((a, b) => {
      if (a[1] === b[1]) return a[0] - b[0];
      return a[1] - b[1];
    });
    const flated = next.flat();

    if (flated.length > row) row = flated.length;

    for (let j = 1; j <= row; j++) {
      if (flated.length >= j) arr[j][i] = flated[j - 1];
      else arr[j][i] = 0;
    }
  }
}
