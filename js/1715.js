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

const n = +inputs[0];
let answer = 0;
const minHeap = new MinHeap();

for (let i = 1; i <= n; i++) {
  minHeap.push(+inputs[i]);
}

while (minHeap.getLength() !== 1) {
  const a = minHeap.pop();
  const b = minHeap.pop();
  const subSum = a + b;
  answer += subSum;
  minHeap.push(subSum);
}

console.log(answer);
