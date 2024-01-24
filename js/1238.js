// floyd warshal
// const fs = require('fs');

// const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

// const [N, M, X] = inputs[0].split(' ').map(Number);

// const roads = Array(N + 1)
//   .fill()
//   .map((_, i) =>
//     Array(N + 1)
//       .fill()
//       .map((_, j) => {
//         if (i === j) return 0;
//         else return Infinity;
//       })
//   );

// for (let i = 1; i <= M; i++) {
//   const [start, end, t] = inputs[i].split(' ').map(Number);
//   roads[start][end] = t;
// }

// for (let k = 1; k <= N; k++) {
//   for (let i = 1; i <= N; i++) {
//     for (let j = 1; j <= N; j++) {
//       roads[i][j] = Math.min(roads[i][k] + roads[k][j], roads[i][j]);
//     }
//   }
// }

// let maxLong = 0;
// for (let i = 1; i <= N; i++) {
//   maxLong = Math.max(maxLong, roads[i][X] + roads[X][i]);
// }

// console.log(maxLong);

// dijkstra
const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

class MinHeap {
  constructor() {
    this.heap = [];
  }

  getLength = () => {
    return this.heap.length;
  };

  push = (node) => {
    this.heap.push(node);
    let i = this.heap.length - 1;
    let parentI = Math.floor((i - 1) / 2);
    while (i > 0 && this.heap[parentI][0] > this.heap[i][0]) {
      this.swap(i, parentI);
      i = parentI;
      parentI = Math.floor((i - 1) / 2);
    }
  };

  pop = () => {
    if (this.heap.length === 1) {
      return this.heap.pop();
    }

    const result = this.heap[0];
    this.heap[0] = this.heap.pop();
    let i = 0;
    while (i * 2 + 1 < this.heap.length) {
      const leftI = i * 2 + 1;
      const rightI = i * 2 + 2;

      let min = this.heap[leftI][0];
      let minI = leftI;

      if (rightI < this.heap.length && this.heap[rightI][0] < min) {
        min = this.heap[rightI][0];
        minI = rightI;
      }
      if (this.heap[i][0] < min) break;
      this.swap(i, minI);
      i = minI;
    }

    return result;
  };

  swap = (a, b) => {
    let temp = this.heap[a];
    this.heap[a] = this.heap[b];
    this.heap[b] = temp;
  };
}

const [N, M, X] = inputs[0].split(' ').map(Number);
const minDist = Array(2)
  .fill()
  .map(() => Array(N + 1).fill(Infinity));
const adjList = Array(2)
  .fill()
  .map(() =>
    Array(N + 1)
      .fill()
      .map(() => [])
  );

for (let i = 1; i <= M; i++) {
  const [start, end, t] = inputs[i].split(' ').map(Number);
  adjList[0][start].push([t, end]);
  adjList[1][end].push([t, start]);
}

dijkstra(0, X);
dijkstra(1, X);

let answer = 0;
for (let i = 1; i <= N; i++) {
  answer = Math.max(answer, minDist[0][i] + minDist[1][i]);
}
console.log(answer);

function dijkstra(level, start) {
  const pq = new MinHeap();
  pq.push([0, start]);
  minDist[level][start] = 0;

  while (pq.getLength() !== 0) {
    const [weight, curr] = pq.pop();

    if (minDist[level][curr] < weight) continue;
    for (let i = 0; i < adjList[level][curr].length; i++) {
      const nextWeight = weight + adjList[level][curr][i][0];
      const next = adjList[level][curr][i][1];

      if (nextWeight < minDist[level][next]) {
        minDist[level][next] = nextWeight;
        pq.push([nextWeight, next]);
      }
    }
  }
}
