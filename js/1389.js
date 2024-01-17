// Floyd warshall
const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m] = inputs[0].split(' ').map(Number);

const relationship = Array(n + 1)
  .fill()
  .map((_, i) =>
    Array(n + 1)
      .fill()
      .map((_, j) => {
        if (i === j) return 0;
        else return Infinity;
      })
  );

for (let i = 1; i <= m; i++) {
  const [a, b] = inputs[i].split(' ').map(Number);
  relationship[a][b] = 1;
  relationship[b][a] = 1;
}

for (let k = 1; k <= n; k++) {
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= n; j++) {
      if (relationship[i][k] + relationship[k][j] < relationship[i][j]) {
        relationship[i][j] = relationship[i][k] + relationship[k][j];
      }
    }
  }
}

const kevinBaconNums = relationship.map(
  (subArr) => subArr.slice(1).reduce((a, b) => a + b),
  0
);

const answer = kevinBaconNums.indexOf(Math.min(...kevinBaconNums));

console.log(answer);

// BFS 풀이
// const fs = require('fs');

// const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

// const [n, m] = inputs[0].split(' ').map(Number);

// const arr = Array(n + 1)
//   .fill()
//   .map(() => []);

// const bacon = Array(n + 1).fill(0);

// for (let i = 1; i <= m; i++) {
//   const [a, b] = inputs[i].split(' ').map(Number);
//   arr[a].push(b);
//   arr[b].push(a);
// }

// for (let i = 1; i <= n; i++) {
//   bfs(i);
// }

// function bfs(start) {
//   const q = [[start, 0]];
//   const isVisited = Array(n + 1).fill(false);

//   while (q.length !== 0) {
//     const [node, count] = q.shift();

//     if (!isVisited[node]) {
//       isVisited[node] = true;
//       bacon[start] += count;
//       arr[node].forEach((el) => q.push([el, count + 1]));
//     }
//   }
// }

// const answer = bacon.indexOf(Math.min(...bacon.slice(1)));

// console.log(answer);
