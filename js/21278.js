const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [N, M] = inputs[0];
let resultMinT = Infinity;
let resultSelected = [1, 2];

const dist = Array(N + 1)
  .fill()
  .map((_, i) =>
    Array(N + 1)
      .fill()
      .map((e, j) => {
        if (i === j) return 0;
        return Infinity;
      })
  );

for (let i = 1; i <= M; i++) {
  const [A, B] = inputs[i];
  dist[A][B] = 1;
  dist[B][A] = 1;
}

for (let k = 1; k <= N; k++) {
  for (let i = 1; i <= N; i++) {
    for (let j = 1; j <= N; j++) {
      dist[i][j] = Math.min(dist[i][k] + dist[k][j], dist[i][j]);
    }
  }
}

const selected = [];

dfs(1);

console.log(resultSelected.join(' ') + ' ' + resultMinT);

function dfs(idx) {
  if (selected.length === 2) {
    let minRoundTSum = 0;
    const [a, b] = selected;

    for (let i = 1; i <= N; i++) {
      minRoundTSum += Math.min(dist[a][i], dist[b][i]) * 2;
    }

    if (minRoundTSum < resultMinT) {
      resultMinT = minRoundTSum;
      resultSelected = [...selected];
    }
    return;
  }

  for (let i = idx; i <= N; i++) {
    if (!isVisited[i]) {
      isVisited[i] = true;
      selected.push(i);
      dfs(idx + 1);
      selected.pop();
      isVisited[i] = false;
    }
  }
}
