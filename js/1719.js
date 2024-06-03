const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [n, m] = inputs[0];

const arr = Array(n + 1)
  .fill()
  .map((_, i) =>
    Array(n + 1)
      .fill()
      .map((e, j) => {
        if (i === j) return 0;
        return Infinity;
      })
  );

const ans = Array(n)
  .fill()
  .map((_, i) =>
    Array(n)
      .fill()
      .map((e, j) => {
        if (i === j) return '-';
        return j + 1;
      })
  );

for (let i = 1; i <= m; i++) {
  const [a, b, c] = inputs[i];
  arr[a][b] = c;
  arr[b][a] = c;
}

for (let k = 1; k <= n; k++) {
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= n; j++) {
      if (arr[i][j] > arr[i][k] + arr[k][j]) {
        ans[i - 1][j - 1] = ans[i - 1][k - 1];
        arr[i][j] = arr[i][k] + arr[k][j];
      }
    }
  }
}

console.log(ans.map((e) => e.join(' ')).join('\n'));
