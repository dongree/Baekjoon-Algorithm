class Node {
  constructor(data, next = null) {
    this.data = data;
    this.next = next;
  }
}

class Queue {
  constructor() {
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  push = (data) => {
    const node = new Node(data);

    if (this.size === 0) {
      this.head = node;
      this.tail = node;
    } else {
      this.tail.next = node;
      this.tail = node;
    }

    this.size++;
  };

  pop = () => {
    if (this.size === 0) {
      return null;
    }

    const poped = this.head.data;
    if (this.size === 1) {
      this.head = null;
      this.tail = null;
    } else {
      this.head = this.head.next;
    }

    this.size--;

    return poped;
  };

  getSize = () => {
    return this.size;
  };
}

const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const t = +inputs[0];
const isVisited = Array(10000).fill(false);
const commands = Array(10000).fill('');
const ans = [];

for (let i = 1; i <= t; i++) {
  const [a, b] = inputs[i].split(' ').map(Number);
  for (let i = 0; i < 10000; i++) {
    isVisited[i] = false;
    commands[i] = '';
  }

  const q = new Queue();

  idx = 0;
  q.push(a);
  isVisited[a] = true;

  while (q.getSize() !== 0) {
    const num = q.pop();

    if (num === b) {
      ans.push(commands[b]);
      break;
    }

    const numD = D(num);
    if (!isVisited[numD]) {
      isVisited[numD] = true;
      commands[numD] = commands[num] + 'D';
      q.push(numD);
    }
    const numS = S(num);
    if (!isVisited[numS]) {
      isVisited[numS] = true;
      commands[numS] = commands[num] + 'S';
      q.push(numS);
    }
    const numL = L(num);
    if (!isVisited[numL]) {
      isVisited[numL] = true;
      commands[numL] = commands[num] + 'L';
      q.push(numL);
    }
    const numR = R(num);
    if (!isVisited[numR]) {
      isVisited[numR] = true;
      commands[numR] = commands[num] + 'R';
      q.push(numR);
    }
  }
}

console.log(ans.join('\n'));

function D(n) {
  return (2 * n) % 10000;
}

function S(n) {
  return n === 0 ? 9999 : n - 1;
}

function L(n) {
  const k = Math.floor(n / 1000);
  n %= 1000;
  return n * 10 + k;
}

function R(n) {
  const k = n % 10;
  n = Math.floor(n / 10);
  return k * 1000 + n;
}
