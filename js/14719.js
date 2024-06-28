const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [H, W] = inputs[0];
const hegihts = inputs[1];

const arr = Array(H)
  .fill()
  .map(() => Array(W).fill(0));

for (let i = 0; i < W; i++) {
  for (let j = 0; j < hegihts[i]; j++) {
    arr[H - j - 1][i] = 1;
  }
}

let ans = 0;

for (let i = 0; i < H; i++) {
  let visited = false;
  let cnt = 0;
  for (let j = 0; j < W; j++) {
    if (arr[i][j] === 1) {
      if (!visited) {
        visited = true;
      } else {
        ans += cnt;
        cnt = 0;
      }
    } else {
      if (visited) cnt++;
    }
  }
}

console.log(ans);
