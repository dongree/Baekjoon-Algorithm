const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const arr = Array(7)
  .fill()
  .map(() => Array(2).fill(0));

const [N, K] = inputs[0];

for (let i = 1; i <= N; i++) {
  const [S, Y] = inputs[i];
  arr[Y][S]++;
}

let result = 0;

for (let i = 1; i <= 6; i++) {
  for (let j = 0; j < 2; j++) {
    if (arr[i][j] === 0) continue;

    result += Math.floor((arr[i][j] - 1) / K) + 1;
  }
}

console.log(result);
