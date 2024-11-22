const fs = require('fs');

const [N, ...arr] = fs.readFileSync('example.txt').toString().trim().split('\n').map(Number);

let k = arr[N - 1];
let ans = 0;

for (let i = N - 2; i >= 0; i--) {
  if (arr[i] >= k) {
    ans += arr[i] - k + 1;
    k = k - 1;
  } else k = arr[i];
}

console.log(ans);
