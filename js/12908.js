const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const coord = [inputs[0], inputs[1]];
const dist = Array(8)
  .fill()
  .map((_, i) =>
    Array(8)
      .fill()
      .map((_, j) => {
        if (i === j) return 0;
        return Infinity;
      })
  );

for (let i = 1; i < 4; i++) {
  const [a, b, c, d] = inputs[i + 1];
  coord.push([a, b]);
  coord.push([c, d]);

  dist[2 * i][2 * i + 1] = 10;
  dist[2 * i + 1][2 * i] = 10;
}

for (let i = 0; i < 8; i++) {
  for (let j = 0; j < 8; j++) {
    if (i === j) continue;
    dist[i][j] = Math.min(dist[i][j], calcDist(coord[i], coord[j]));
  }
}

for (let k = 0; k < 8; k++) {
  for (let i = 0; i < 8; i++) {
    for (let j = 0; j < 8; j++) {
      dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }
}

console.log(dist[0][1]);

function calcDist(a, b) {
  const [y1, x1] = a;
  const [y2, x2] = b;

  return Math.abs(y1 - y2) + Math.abs(x1 - x2);
}
