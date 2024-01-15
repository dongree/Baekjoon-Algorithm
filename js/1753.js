const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

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
    while (i > 0 && this.heap[parentI] > this.heap[i]) {
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

      let min = this.heap[leftI];
      let minI = leftI;

      if (rightI < this.heap.length && min > this.heap[rightI]) {
        min = this.heap[rightI];
        minI = rightI;
      }
      if (this.heap[i] < min) break;
      this.swap(i, minI);
      i = minI;
    }

    return result;
  };

  swap = (a, b) => {
    const temp = this.heap[a];
    this.heap[a] = this.heap[b];
    this.heap[b] = temp;
  };
}

const [V, E] = inputs[0].split(' ').map(Number);
const K = +inputs[1];

const adjList = Array(V + 1)
  .fill()
  .map(() => []);
const minDist = Array(V + 1).fill(Infinity);

for (let i = 2; i < inputs.length; i++) {
  const [u, v, w] = inputs[i].split(' ').map(Number);
  adjList[u].push([w, v]);
}

dijkstra(K);

const answer = minDist
  .map((el) => {
    if (el === Infinity) return 'INF';
    else return el;
  })
  .slice(1)
  .join('\n');

console.log(answer);

function dijkstra(start) {
  minDist[start] = 0;
  const pq = new MinHeap();
  pq.push([0, start]);
  while (pq.getLength() !== 0) {
    const [weight, current] = pq.pop();

    if (weight > minDist[current]) continue;
    for (let i = 0; i < adjList[current].length; i++) {
      const next = adjList[current][i][1];
      const nextWeight = weight + adjList[current][i][0];
      if (nextWeight < minDist[next]) {
        minDist[next] = nextWeight;
        pq.push([nextWeight, next]);
      }
    }
  }
}
