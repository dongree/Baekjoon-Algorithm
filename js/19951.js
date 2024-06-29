const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [N, M] = inputs[0];
const arr = inputs[1];

const ps = Array(N + 2).fill(0);

for (let i = 2; i < 2 + M; i++) {
  const [a, b, k] = inputs[i];
  ps[a] += k;
  ps[b + 1] -= k;
}

for (let i = 1; i <= N; i++) {
  ps[i] += ps[i - 1];
}
for (let i = 0; i < N; i++) {
  arr[i] += ps[i + 1];
}

console.log(arr.join(' '));
