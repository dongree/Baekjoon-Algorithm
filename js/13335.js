const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [n, L, w] = inputs[0].split(' ').map(Number);
const truckWeights = inputs[1].split(' ').map(Number);
const q = [];
let idx = 0;
let t = 0;
let currW = 0;

while (true) {
  if (idx === n) {
    t += L;
    break;
  }

  t++;

  if (q.length === L) {
    currW -= q.shift();
  }

  const tw = truckWeights[idx];

  if (currW + tw <= w) {
    currW += tw;
    q.push(tw);
    idx++;
  } else {
    q.push(0);
  }
}

console.log(t);
