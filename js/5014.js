const fs = require('fs');

let [F, S, G, U, D] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

const isVisited = Array(1000001).fill(false);

console.log(bfs());

function bfs() {
  const q = [];
  q.push([S, 0]);
  isVisited[S] = true;

  while (q.length !== 0) {
    const [num, cnt] = q.shift();
    if (num === G) {
      return cnt;
    }

    for (let e of [num + U, num - D]) {
      if (1 <= e && e <= F && !isVisited[e]) {
        isVisited[e] = true;
        q.push([e, cnt + 1]);
      }
    }
  }

  return 'use the stairs';
}

// while (S !== G) {
//   if (S < G) {
//     S += U;
//   } else if (S > G) {
//     S -= D;
//   }
//   cnt++;
// }

// console.log(cnt);
