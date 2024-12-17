const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const T = +getLine();
const ans = [];

for (let t = 0; t < T; t++) {
  const [sx, sy, tx, ty] = getLine().split(' ').map(Number);

  const n = +getLine();
  let cnt = 0;

  for (let i = 0; i < n; i++) {
    const [x, y, r] = getLine().split(' ').map(Number);

    if ((x - sx) ** 2 + (y - sy) ** 2 <= r ** 2) cnt++;
    if ((x - tx) ** 2 + (y - ty) ** 2 <= r ** 2) cnt++;
    if ((x - sx) ** 2 + (y - sy) ** 2 <= r ** 2 && (x - tx) ** 2 + (y - ty) ** 2 <= r ** 2)
      cnt -= 2;
  }
  ans.push(cnt);
}

console.log(ans.join('\n'));
