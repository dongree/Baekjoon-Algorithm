const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let tc = +inputs[0];

let idx = 1;
const answer = [];

while (tc--) {
  const edges = [];
  let [N, M, W] = inputs[idx].split(' ').map(Number);
  const dist = Array(N + 1).fill(10000000);

  idx++;
  while (M--) {
    const [S, E, T] = inputs[idx].split(' ').map(Number);
    edges.push([S, E, T]);
    edges.push([E, S, T]);
    idx++;
  }
  while (W--) {
    const [S, E, T] = inputs[idx].split(' ').map(Number);
    edges.push([S, E, -T]);
    idx++;
  }

  bellmanFord();

  function bellmanFord() {
    dist[1] = 0;
    for (let i = 1; i < N; i++) {
      for (let j = 0; j < edges.length; j++) {
        const [from, to, cost] = edges[j];
        if (dist[from] + cost < dist[to]) dist[to] = dist[from] + cost;
      }
    }

    for (let j = 0; j < edges.length; j++) {
      const [from, to, cost] = edges[j];
      if (dist[from] + cost < dist[to]) {
        answer.push('YES');
        return;
      }
    }

    answer.push('NO');
    return;
  }
}

console.log(answer.join('\n'));
