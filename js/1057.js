const fs = require('fs');

let [N, a, b] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

if (a > b) {
  [a, b] = [b, a];
}

let cnt = 1;
let flag = false;

while (N !== 1) {
  if (a % 2 === 1 && b - a === 1) {
    console.log(cnt);
    flag = true;
    return;
  }

  a = Math.floor((a + 1) / 2);
  b = Math.floor((b + 1) / 2);

  cnt++;
  N /= 2;
}

if (!flag) console.log(-1);
