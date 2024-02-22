const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];

const [N, M] = getLine();
const arr = [];
const sArr = Array(N + 1)
  .fill()
  .map(() => Array(M + 1).fill(0));
const ans = [];

for (let i = 0; i < N; i++) {
  arr.push(getLine());
}

for (let i = 1; i <= N; i++) {
  for (let j = 1; j <= M; j++) {
    sArr[i][j] =
      arr[i - 1][j - 1] + sArr[i][j - 1] + sArr[i - 1][j] - sArr[i - 1][j - 1];
  }
}

let [K] = getLine();
while (K--) {
  const [i, j, x, y] = getLine();
  ans.push(sArr[x][y] - sArr[x][j - 1] - sArr[i - 1][y] + sArr[i - 1][j - 1]);
}

console.log(ans.join('\n'));
