const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const answer = [];

let idx = 1;
while (idx < inputs.length) {
  const [V, E] = inputs[idx].split(' ').map(Number);
  const graph = Array(V + 1)
    .fill()
    .map(() => []);
  idx++;
  for (let i = 0; i < E; i++) {
    const [a, b] = inputs[idx].split(' ').map(Number);
    graph[a].push(b);
    graph[b].push(a);
    idx++;
  }

  const nodeColors = Array(V + 1).fill(0);

  let tAnswer = 'YES';

  outer: for (let i = 1; i <= V; i++) {
    if (nodeColors[i] !== 0) continue;
    const q = [[i, 'red']];
    q.push([i]);

    nodeColors[i] = 'red';

    while (q.length !== 0) {
      const [node, color] = q.shift();

      for (let i = 0; i < graph[node].length; i++) {
        if (nodeColors[graph[node][i]] === 0) {
          const nextColor = color === 'red' ? 'blue' : 'red';
          nodeColors[graph[node][i]] = nextColor;
          q.push([graph[node][i], nextColor]);
        } else if (nodeColors[graph[node][i]] === color) {
          tAnswer = 'NO';
          break outer;
        }
      }
    }
  }
  answer.push(tAnswer);
}
console.log(answer.join('\n'));
