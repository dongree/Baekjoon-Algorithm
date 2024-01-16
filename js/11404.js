const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];
const m = +inputs[1];

const minCost = Array(n + 1)
  .fill()
  .map((_, i) =>
    Array(n + 1)
      .fill()
      .map((_, j) => {
        if (i === j) return 0;
        else return Infinity;
      })
  );

for (let i = 2; i < m + 2; i++) {
  const [a, b, c] = inputs[i].split(' ').map(Number);
  if (c < minCost[a][b]) minCost[a][b] = c;
}

for (let k = 1; k <= n; k++) {
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= n; j++) {
      if (minCost[i][k] + minCost[k][j] < minCost[i][j]) {
        minCost[i][j] = minCost[i][k] + minCost[k][j];
      }
    }
  }
}

for (let i = 1; i <= n; i++) {
  for (let j = 1; j <= n; j++) {
    if (minCost[i][j] === Infinity) {
      minCost[i][j] = 0;
    }
  }
}

const answer = minCost
  .slice(1)
  .map((subArr) => subArr.slice(1).join(' '))
  .join('\n');

console.log(answer);
