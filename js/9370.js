class MinHeap {
  constructor() {
    this.heap = [];
  }

  size = () => {
    return this.heap.length;
  };

  push = (node) => {
    this.heap.push(node);
    let i = this.heap.length - 1;
    let parentI = Math.floor((i - 1) / 2);

    while (i > 0 && this.heap[i][0] < this.heap[parentI][0]) {
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

    while (2 * i + 1 < this.heap.length) {
      const leftI = 2 * i + 1;
      const rightI = 2 * i + 2;

      let minI = leftI;

      if (
        rightI < this.heap.length &&
        this.heap[rightI][0] < this.heap[leftI][0]
      ) {
        minI = rightI;
      }

      if (this.heap[i][0] < this.heap[minI][0]) break;
      this.swap(i, minI);
      i = minI;
    }

    return result;
  };

  swap = (a, b) => {
    [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
  };
}

const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];

let [T] = getLine();
const answer = [];

while (T--) {
  let [n, m, t] = getLine();
  const [s, g, h] = getLine();

  const adjList = Array(n + 1)
    .fill()
    .map(() => []);
  const minDistS = Array(n + 1).fill(Infinity);
  const minDistG = Array(n + 1).fill(Infinity);
  const minDistH = Array(n + 1).fill(Infinity);

  while (m--) {
    const [a, b, d] = getLine();
    adjList[a].push([d, b]);
    adjList[b].push([d, a]);
  }

  dijkstra(s, minDistS);
  dijkstra(g, minDistG);
  dijkstra(h, minDistH);

  const temp = [];
  while (t--) {
    const [x] = getLine();

    if (
      minDistS[x] !== Infinity &&
      (minDistS[x] === minDistS[g] + minDistG[h] + minDistH[x] ||
        minDistS[x] === minDistS[h] + minDistH[g] + minDistG[x])
    ) {
      temp.push(x);
    }
  }

  answer.push(temp.sort((a, b) => a - b).join(' '));

  function dijkstra(start, minDist) {
    const pq = new MinHeap();
    pq.push([0, start]);
    minDist[start] = 0;

    while (pq.size() !== 0) {
      const [weight, node] = pq.pop();

      for (let i = 0; i < adjList[node].length; i++) {
        const nextWeight = weight + adjList[node][i][0];
        const nextNode = adjList[node][i][1];

        if (nextWeight < minDist[nextNode]) {
          minDist[nextNode] = nextWeight;
          pq.push([nextWeight, nextNode]);
        }
      }
    }
  }
}

console.log(answer.join('\n'));
