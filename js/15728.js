const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [N, K] = inputs[0];

const arr1 = inputs[1];
const arr2 = inputs[2];

const isVisited = Array(N).fill(false);
let ans;

for (let i = 0; i <= K; i++) {
  ans = -Infinity;
  let idx = 0;
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (isVisited[j]) continue;
      if (arr1[i] * arr2[j] > ans) {
        ans = arr1[i] * arr2[j];
        idx = j;
      }
    }
  }
  isVisited[idx] = true;
}

console.log(ans);
