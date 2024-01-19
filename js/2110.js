const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [N, C] = inputs[0].split(' ').map(Number);

const loc = [];
for (let i = 1; i <= N; i++) {
  loc.push(+inputs[i]);
}

loc.sort((a, b) => a - b);

let start = 1;
let end = loc[loc.length - 1] - loc[0];

while (start <= end) {
  const mid = Math.floor((start + end) / 2);

  let cnt = 1;
  let prev = loc[0];
  for (let i = 1; i < N; i++) {
    if (loc[i] - prev < mid) continue;
    prev = loc[i];
    cnt++;
  }

  if (cnt < C) end = mid - 1;
  else start = mid + 1;
}

console.log(end);
