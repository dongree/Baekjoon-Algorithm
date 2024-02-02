const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);
const edges = [];
const dist = Array(N + 1).fill(Infinity);
const answer = [];

for (let i = 1; i <= M; i++) {
  edges.push(inputs[i].split(' ').map(Number));
}

if (bellmanford(1)) {
  answer.push(-1);
} else {
  for (let i = 2; i <= N; i++) {
    if (dist[i] === Infinity) answer.push(-1);
    else answer.push(dist[i]);
  }
}

console.log(answer.join('\n'));

function bellmanford(n) {
  dist[n] = 0;

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < edges.length; j++) {
      const [from, to, cost] = edges[j];
      if (dist[from] !== Infinity && dist[from] + cost < dist[to]) {
        dist[to] = dist[from] + cost;
        if (i === N - 1) return true;
      }
    }
  }
  return false;
}
