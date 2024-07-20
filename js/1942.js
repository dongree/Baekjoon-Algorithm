const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const result = [];

for (let i = 0; i < 3; i++) {
  const [start, end] = inputs[i].split(' ');

  const s = getSeoncds(start);
  let e = getSeoncds(end);

  let cnt = 0;

  if (s > e) e += 60 * 60 * 24;

  for (let i = s; i <= e; i++) {
    if (isRight(i)) cnt++;
  }

  result.push(cnt);
}

console.log(result.join('\n'));

function getSeoncds(time) {
  const [h, m, s] = time.split(':');

  return +h * 60 * 60 + +m * 60 + +s;
}

function isRight(s) {
  const h = Math.floor(s / (60 * 60)) % 24;
  s %= 60 * 60;
  const m = Math.floor(s / 60);
  s %= 60;

  const n = h * 10000 + m * 100 + s;

  if (n % 3 === 0) return true;
  return false;
}
