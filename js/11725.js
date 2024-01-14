const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];

const adjList = {};
for (let i = 1; i <= n; i++) {
  adjList[i] = [];
}
const parents = Array(n + 1).fill(-1);

for (let i = 1; i < n; i++) {
  const [a, b] = inputs[i].split(' ').map(Number);
  adjList[a.toString()].push(b);
  adjList[b.toString()].push(a);
}

const q = [];
q.push(1);
parents[1] = 0;

while (q.length !== 0) {
  const front = q.shift();

  adjList[front.toString()].forEach((e) => {
    if (parents[e] === -1) {
      q.push(e);
      parents[e] = front;
    }
  });
}

console.log(parents.slice(2).join('\n'));
