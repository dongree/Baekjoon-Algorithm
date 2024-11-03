// my solution : dfs

// const fs = require('fs');

// const inputs = fs
//   .readFileSync('example.txt')
//   .toString()
//   .trim()
//   .split('\n')
//   .map((e) => e.split(' ').map(Number));

// const [V, E] = inputs[0];
// const visited = Array(V + 1)
//   .fill()
//   .map(() => Array(V + 1).fill(false));

// const adjList = Array(V + 1)
//   .fill()
//   .map(() => []);

// for (let i = 1; i <= E; i++) {
//   const [a, b] = inputs[i];

//   adjList[a].push(b);
//   adjList[b].push(a);
// }

// let start = 0;
// let startOutDegree = 0;

// for (let i = 1; i <= V; i++) {
//   if (adjList[i].length > startOutDegree) {
//     startOutDegree = adjList[i].length;
//     start = i;
//   }
// }

// let flag = false;

// search(start, 0);

// if (flag) console.log('YES');
// else console.log('NO');

// function search(start, cnt) {
//   if (flag) return;

//   if (cnt === E) {
//     flag = true;
//     return;
//   }

//   for (let i = 0; i < adjList[start].length; i++) {
//     const next = adjList[start][i];
//     if (!visited[start][next]) {
//       visited[start][next] = true;
//       visited[next][start] = true;
//       search(next, cnt + 1);
//     }
//   }
// }

// second solution : union-find, Eulerian path

const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [V, E] = inputs[0];

const parent = Array(V + 1)
  .fill()
  .map((_, idx) => idx);

const adjList = Array(V + 1)
  .fill()
  .map(() => []);

for (let i = 1; i <= E; i++) {
  const [a, b] = inputs[i];

  adjList[a].push(b);
  adjList[b].push(a);
  unionParent(a, b);
}

let flag = true;

for (let i = 2; i <= V; i++) {
  if (!sameParent(1, i)) {
    flag = false;
    break;
  }
}

if (!flag) console.log('NO');
else {
  let oddCnt = 0;

  for (let i = 1; i <= V; i++) {
    if (adjList[i].length % 2 === 1) oddCnt++;
  }

  if (oddCnt === 2 || oddCnt === 0) console.log('YES');
  else console.log('NO');
}

function getParent(x) {
  if (x === parent[x]) return x;
  else return (parent[x] = getParent(parent[x]));
}

function unionParent(a, b) {
  a = getParent(a);
  b = getParent(b);

  if (a < b) {
    parent[b] = a;
  } else if (a > b) {
    parent[a] = b;
  }
}

function sameParent(a, b) {
  a = getParent(a);
  b = getParent(b);

  return a === b;
}
