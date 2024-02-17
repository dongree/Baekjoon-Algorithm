const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let nowLine = 0;
const getQuery = () => inputs[nowLine++];

const [n, k] = getQuery();
const arr = Array(n + 1)
  .fill()
  .map(() => Array(n + 1).fill(0));
const answer = [];

for (let i = 0; i < k; i++) {
  const [a, b] = getQuery();
  arr[a][b] = -1;
  arr[b][a] = 1;
}

for (let m = 1; m <= n; m++) {
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= n; j++) {
      if (arr[i][j] === 0 && arr[i][m] === -1 && arr[m][j] === -1) {
        arr[i][j] = -1;
        arr[j][i] = 1;
      }
    }
  }
}

const [s] = getQuery();
for (let i = 0; i < s; i++) {
  const [a, b] = getQuery();
  answer.push(arr[a][b]);
}

console.log(answer.join('\n'));
