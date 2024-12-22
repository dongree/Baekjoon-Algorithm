const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, H, W] = inputs[0].split(' ').map(Number);

const arr = [];

for (let i = 1; i <= H; i++) {
  arr.push(inputs[i].split(''));
}

let s = '';

for (let k = 0; k < N; k++) {
  let c = '?';
  a: for (let i = 0; i < H; i++) {
    for (let j = k * W; j < W * (k + 1); j++) {
      if (arr[i][j] !== '?') {
        c = arr[i][j];
        break a;
      }
    }
  }
  s += c;
}

console.log(s);
