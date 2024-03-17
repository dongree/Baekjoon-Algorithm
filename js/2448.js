const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString();

const arr = Array(N)
  .fill()
  .map(() => Array(N * 2 - 1).fill(' '));

const tree = ['  *  ', ' * * ', '*****'];

star(0, 0, N);

console.log(arr.map((e) => e.join('')).join('\n'));

function star(y, x, N) {
  if (N === 3) {
    for (let i = 0; i < 3; i++) {
      for (let j = 0; j < 5; j++) {
        arr[y + i][x + j] = tree[i][j];
      }
    }
    return;
  }

  star(y, x + N / 2, N / 2);
  star(y + N / 2, x, N / 2);
  star(y + N / 2, x + N, N / 2);
}
