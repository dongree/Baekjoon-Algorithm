const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [x1, y1, x2, y2] = inputs[0].split(' ').map(Number);
const [x3, y3, x4, y4] = inputs[1].split(' ').map(Number);

if (
  ccw(x1, y1, x3, y3, x2, y2) * ccw(x1, y1, x4, y4, x2, y2) < 0 &&
  ccw(x3, y3, x1, y1, x4, y4) * ccw(x3, y3, x2, y2, x4, y4) < 0
) {
  console.log(1);
} else {
  console.log(0);
}

function ccw(ax, ay, bx, by, cx, cy) {
  return (bx - ax) * (cy - ay) - (cx - ax) * (by - ay);
}
