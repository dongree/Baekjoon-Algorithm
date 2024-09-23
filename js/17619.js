const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const k = +inputs[0];
const arr = inputs[1].split(' ').map(Number);
const sum = arr.reduce((a, b) => a + b, 0);
const isVisited = Array(3000000).fill(false);
let cnt = 0;

recur(0, 0);

console.log(sum - cnt);

function recur(n, curr) {
  if (curr >= 1 && !isVisited[curr]) {
    cnt++;
    isVisited[curr] = true;
  }

  if (n === k) return;

  recur(n + 1, curr);
  recur(n + 1, curr + arr[n]);
  recur(n + 1, curr - arr[n]);
}
