const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, H] = inputs.shift().split(' ').map(Number);
const bottom = Array(H + 1).fill(0);
const top = Array(H + 1).fill(0);

inputs.forEach((e, i) => {
  if (i % 2 === 0) bottom[+e]++;
  else top[H - e + 1]++;
});

for (let i = 1; i <= H; i++) {
  top[i] += top[i - 1];
  bottom[H - i] += bottom[H - i + 1];
}

let min = Infinity;
let cnt = 0;
for (let i = 1; i <= H; i++) {
  if (top[i] + bottom[i] < min) {
    min = top[i] + bottom[i];
    cnt = 1;
  } else if (top[i] + bottom[i] === min) cnt++;
}

console.log(min, cnt);
