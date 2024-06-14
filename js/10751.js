const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const s = inputs[1];

const L = Array(N).fill(0);
const R = Array(N).fill(0);

L[0] = s[0] === 'C' ? 1 : 0;
for (let i = 1; i < N; i++) {
  L[i] = L[i - 1] + (s[i] === 'C' ? 1 : 0);
}

R[N - 1] = s[N - 1] === 'W' ? 1 : 0;
for (let i = N - 2; i >= 0; i--) {
  R[i] = R[i + 1] + (s[i] === 'W' ? 1 : 0);
}

let ans = 0;
for (let i = 0; i < N; i++) {
  if (s[i] === 'O') {
    ans += L[i - 1] * R[i + 1];
  }
}

console.log(ans);
