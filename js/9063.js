const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const N = +getLine();

let minY = Infinity;
let maxY = -Infinity;
let minX = Infinity;
let maxX = -Infinity;

for (let i = 0; i < N; i++) {
  const [x, y] = getLine().split(' ').map(Number);

  if (x < minX) minX = x;
  if (x > maxX) maxX = x;
  if (y < minY) minY = y;
  if (y > maxY) maxY = y;
}

const result = (maxX - minX) * (maxY - minY);
console.log(result);
