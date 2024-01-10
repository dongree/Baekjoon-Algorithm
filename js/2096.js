// js는 메모리 초과로 통과가 안 됨.
const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];
const arr = [[0, 0, 0]];

for (let i = 1; i <= n; i++) {
  const subArr = inputs[i].split(' ').map(Number);
  arr.push(subArr);
}

let pre = Array(2)
  .fill()
  .map(() => Array(3).fill(0));

const curr = Array(2)
  .fill()
  .map(() => Array(3).fill(0));

for (let i = 1; i <= n; i++) {
  curr[0][0] = arr[i][0] + Math.max(pre[0][0], pre[0][1]);
  curr[0][1] = arr[i][1] + Math.max(pre[0][0], pre[0][1], pre[0][2]);
  curr[0][2] = arr[i][2] + Math.max(pre[0][1], pre[0][2]);

  curr[1][0] = arr[i][0] + Math.min(pre[1][0], pre[1][1]);
  curr[1][1] = arr[i][1] + Math.min(pre[1][0], pre[1][1], pre[1][2]);
  curr[1][2] = arr[i][2] + Math.min(pre[1][1], pre[1][2]);

  pre = [...curr].map((arr) => [...arr]);
}

console.log(Math.max(...curr[0]), Math.min(...curr[1]));
