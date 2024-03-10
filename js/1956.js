const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [V, E] = inputs[0].split(' ').map(Number);

const arr = Array(V + 1)
  .fill()
  .map(() => Array(V + 1).fill(Infinity));

for (let i = 1; i <= E; i++) {
  const [a, b, c] = inputs[i].split(' ').map(Number);
  arr[a][b] = c;
}

for (let k = 1; k <= V; k++) {
  for (let i = 1; i <= V; i++) {
    for (let j = 1; j <= V; j++) {
      arr[i][j] = Math.min(arr[i][j], arr[i][k] + arr[k][j]);
    }
  }
}
a
let answer = Infinity;
for (let i = 1; i <= V; i++) {
  answer = Math.min(answer, arr[i][i]);
}

console.log(answer === Infinity ? -1 : answer);
