const fs = require('fs');

const [N, ...arr] = fs.readFileSync('example.txt').toString().trim().split('\n').map(Number);

let top = 0;
let cnt = 0;
const result = [];

for (let i = 0; i < N; i++) {
  if (arr[i] > top) {
    top = arr[i];
    cnt++;
  }
}
result.push(cnt);

top = 0;
cnt = 0;

for (let i = N - 1; i >= 0; i--) {
  if (arr[i] > top) {
    top = arr[i];
    cnt++;
  }
}
result.push(cnt);

console.log(result.join('\n'));
