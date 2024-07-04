const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let s = inputs[0];
const target = inputs[1];
const n = target.length;

let cnt = 0;

while (true) {
  const idx = s.search(target);
  if (idx === -1) break;

  s = s.slice(idx + n);
  cnt++;
}

console.log(cnt);
