// 0-1 bfs
const fs = require('fs');

const [n, k] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

const MAX = 100000;

const isVisited = Array(MAX).fill(false);

if (n >= k) {
  console.log(n - k);
} else {
  console.log(bfs());
}

function bfs() {
  const dq = [[n, 0]];
  isVisited[n] = true;

  while (dq.length !== 0) {
    const [loc, cnt] = dq.shift();

    if (loc === k) {
      return cnt;
    }

    for (next of [loc * 2, loc - 1, loc + 1]) {
      if (!isVisited[next] && 0 <= next && next <= MAX) {
        isVisited[next] = true;
        if (next === loc * 2) {
          dq.unshift([next, cnt]);
        } else {
          dq.push([next, cnt + 1]);
        }
      }
    }
  }
}

// queue
// const fs = require('fs');

// const [n, k] = fs
//   .readFileSync('example.txt')
//   .toString()
//   .trim()
//   .split(' ')
//   .map(Number);

// const MAX = 100000;

// const isVisited = Array(MAX).fill(false);

// if (n >= k) {
//   console.log(n - k);
// } else {
//   console.log(bfs());
// }

// function bfs() {
//   const q = [[n, 0]];
//   isVisited[n] = true;

//   let idx = 0;
//   while (q.length !== idx) {
//     const [loc, cnt] = q[idx++];

//     if (loc === k) {
//       return cnt;
//     }

//     for (next of [loc * 2, loc - 1, loc + 1]) {
//       if (!isVisited[next] && 0 <= next && next <= MAX) {
//         isVisited[next] = true;
//         if (next === loc * 2) {
//           q.push([next, cnt]);
//         } else {
//           q.push([next, cnt + 1]);
//         }
//       }
//     }
//   }
// }
