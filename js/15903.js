class MinHeap {
  constructor() {
    this.heap = [];
  }

  push = (node) => {
    this.heap.push(node);
    let i = this.heap.length - 1;
    let parentI = Math.floor((i - 1) / 2);
    while (i > 0 && this.heap[i] < this.heap[parentI]) {
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

      let minI = leftI;
      if (rightI < this.heap.length && this.heap[rightI] < this.heap[minI]) {
        minI = rightI;
      }

      if (this.heap[i] < this.heap[minI]) break;
      this.swap(i, minI);
      i = minI;
    }

    return result;
  };

  top = () => {
    if (this.heap.length) {
      return this.heap[0];
    }
  };

  size = () => {
    return this.heap.length;
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
  .map((e) => e.split(' ').map(BigInt));

const pq = new MinHeap();

let [n, m] = inputs[0];
inputs[1].forEach((e) => pq.push(e));

while (m--) {
  const a = pq.pop();
  const b = pq.pop();
  const k = a + b;

  pq.push(k);
  pq.push(k);
}

let ans = 0n;

while (pq.size() !== 0) {
  ans += pq.pop();
}

console.log(ans.toString());
