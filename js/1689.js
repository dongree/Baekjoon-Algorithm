const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().split('\n');

const N = +inputs[0];
const arr = [];

for (let i = 1; i <= N; i++) {
  const [a, b] = inputs[i].split(' ').map(Number);
  arr.push([a, 1]);
  arr.push([b, -1]);
}

arr.sort((a, b) => {
  if (a[0] === b[0]) return a[1] - b[1];
  return a[0] - b[0];
});

let ans = 0;
let k = 0;
for (let i = 0; i < arr.length; i++) {
  k += arr[i][1];
  if (k > ans) ans = k;
}

console.log(ans);
