const fs = require('fs');

const [N, M, L] = fs.readFileSync('example.txt').toString().trim().split(' ').map(Number);

const arr = Array(N).fill(0);

let cnt = 0;
let idx = 0;

while (true) {
  if (arr[idx] < M) {
    if (arr[idx] % 2 === 0) {
      idx = idx - L < 0 ? idx - L + N : idx - L;
    } else {
      idx = (idx + L) % N;
    }
    arr[idx]++;

    if (arr[idx] === M) break;
  }
  cnt++;
}

console.log(cnt);
