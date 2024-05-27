const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);

const adjList = Array(N + 1)
  .fill()
  .map(() => []);

const inDegree = Array(N + 1).fill(0);

for (let i = 1; i <= M; i++) {
  const arr = inputs[i].split(' ').map(Number);
  const n = arr[0];
  for (let i = 1; i < n; i++) {
    adjList[arr[i]].push(arr[i + 1]);
    inDegree[arr[i + 1]]++;
  }
}

const ans = [];

let idx = 0;
const q = [];
for (let i = 1; i <= N; i++) {
  if (inDegree[i] === 0) q.push(i);
}

while (q.length !== idx) {
  const n = q[idx++];
  ans.push(n);

  for (let i = 0; i < adjList[n].length; i++) {
    const nn = adjList[n][i];
    inDegree[nn]--;
    if (inDegree[nn] === 0) q.push(nn);
  }
}

console.log(ans.length !== N ? 0 : ans.join('\n'));
