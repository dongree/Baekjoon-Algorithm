const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const honnies = inputs[1].split(' ').map(Number);

const ps = Array(N + 1).fill(0);

for (let i = 1; i <= N; i++) {
  ps[i] += ps[i - 1] + honnies[i - 1];
}

let ans = 0;

// 꿀 벌 벌
for (let i = 1; i < N - 1; i++) {
  ans = Math.max(ans, ps[N - 1] - honnies[i] + ps[i]);
}

// 벌 꿀 벌
for (let i = 1; i < N - 1; i++) {
  ans = Math.max(ans, ps[i + 1] - ps[1] + ps[N - 1] - ps[i]);
}

// 벌 벌 꿀
for (let i = 1; i < N - 1; i++) {
  ans = Math.max(ans, ps[N] - ps[1] - honnies[i] + ps[N] - ps[i + 1]);
}

console.log(ans);
