const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];
const s = new Set();

let [N, M] = getLine();

const train = Array(N + 1).fill(0);

while (M--) {
  const line = getLine();

  if (line[0] === 1) {
    train[line[1]] |= 1 << line[2];
  } else if (line[0] === 2) {
    train[line[1]] &= ~(1 << line[2]);
  } else if (line[0] === 3) {
    train[line[1]] <<= 1;
    train[line[1]] &= ~(1 << 21);
  } else if (line[0] === 4) {
    train[line[1]] >>= 1;
    train[line[1]] &= ~1;
  }
}

for (let i = 1; i <= N; i++) {
  s.add(train[i]);
}

console.log(s.size);
