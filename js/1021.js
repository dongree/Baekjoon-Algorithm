class Node {
  constructor(data, next = null, prev = null) {
    this.data = data;
    this.next = next;
    this.prev = prev;
  }
}

class Deque {
  constructor() {
    this.size = 0;
    this.front = null;
    this.rear = null;
  }

  pushFront = (data) => {
    const node = new Node(data);

    if (this.size === 0) {
      this.front = node;
      this.rear = node;
    } else {
      const frontNode = this.front;
      frontNode.prev = node;
      node.next = frontNode;
      this.front = node;
    }

    this.size++;
  };

  popFront = () => {
    if (this.size === 0) return null;

    const poped = this.front.data;

    if (this.size === 1) {
      this.size = 0;
      this.front = null;
      this.rear = null;
    } else {
      this.front = this.front.next;
      this.front.prev = null;
      this.size--;
    }

    return poped;
  };

  pushBack = (data) => {
    const node = new Node(data);

    if (this.size === 0) {
      this.front = node;
      this.rear = node;
    } else {
      const rearNode = this.rear;
      rearNode.next = node;
      node.prev = rearNode;
      this.rear = node;
    }

    this.size++;
  };

  popBack = () => {
    if (this.size === 0) return null;

    const poped = this.rear.data;

    if (this.size === 1) {
      this.size = 0;
      this.front = null;
      this.rear = null;
    } else {
      this.rear = this.rear.prev;
      this.rear.next = null;
      this.size--;
    }

    return poped;
  };

  getFront = () => {
    if (this.size === 0) return null;

    return this.front.data;
  };

  getBack = () => {
    if (this.size === 0) return null;

    return this.rear.data;
  };

  getSize = () => {
    return this.size;
  };

  getIdx = (target) => {
    let node = this.front;

    for (let i = 0; i < this.size; i++) {
      if (node.data === target) return i;
      node = node.next;
    }

    return null;
  };
}

const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);
const arr = inputs[1].split(' ').map(Number);
let ans = 0;

const dq = new Deque();

for (let i = 1; i <= N; i++) {
  dq.pushBack(i);
}

arr.forEach((e) => {
  const idx = dq.getIdx(e);
  const cri = Math.floor(dq.getSize() / 2);

  if (idx <= cri) {
    while (dq.getFront() !== e) {
      const k = dq.popFront();
      dq.pushBack(k);
      ans++;
    }
  } else {
    while (dq.getFront() !== e) {
      const k = dq.popBack();
      dq.pushFront(k);
      ans++;
    }
  }

  dq.popFront();
});

console.log(ans);
