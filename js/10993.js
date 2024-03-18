const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString();

const arr =
  N % 2 === 0
    ? Array(2 ** N - 1)
        .fill()
        .map((_, i) => Array(2 ** (N + 1) - 2 - i).fill(' '))
    : Array(2 ** N - 1)
        .fill()
        .map((_, i) => Array(2 ** (N + 1) - 2 - (2 ** N - 2 - i)).fill(' '));

if (N % 2 === 0) star(0, 0, N);
else star(2 ** N - 2, 0, N);

console.log(arr.map((e) => e.join('')).join('\n'));

function star(y, x, N) {
  if (N === 0) return;
  if (N % 2 === 0) {
    let k = 1;
    for (let i = y; i < y + 2 ** N - 1; i++) {
      if (i === y) {
        for (let j = x; j < x + 2 ** (N + 1) - 3; j++) {
          arr[i][j] = '*';
        }
      } else {
        arr[i][x + k] = '*';
        arr[i][x + 2 ** (N + 1) - 4 - k] = '*';
        k++;
      }
    }
    star(y + (2 ** N / 2 - 1), x + 2 ** N / 2, N - 1);
  } else {
    let k = 1;
    for (let i = y; i > y - 2 ** N + 1; i--) {
      if (i === y) {
        for (let j = x; j < x + 2 ** (N + 1) - 3; j++) {
          arr[i][j] = '*';
        }
      } else {
        arr[i][x + k] = '*';
        arr[i][x + 2 ** (N + 1) - 4 - k] = '*';
        k++;
      }
    }
    star(y - (2 ** N / 2 - 1), x + 2 ** N / 2, N - 1);
  }
}
