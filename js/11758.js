const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [x1, y1] = inputs[0];
const [x2, y2] = inputs[1];
const [x3, y3] = inputs[2];

console.log(ccw(x1, y1, x2, y2, x3, y3));

function ccw(x1, y1, x2, y2, x3, y3) {
  const k = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
  if (k > 0) return 1;
  else if (k < -0) return -1;
  return 0;
}
