const fs = require('fs');
const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m] = inputs[0].split(' ').map(Number);
const map = new Map();

for (let i = 1; i <= n; i++) {
  map.set(inputs[i], 1);
}

let result = 0;

for (let i = n + 1; i <= n + m; i++) {
  if (map.get(inputs[i]) === 1) result++;
}

console.log(result);
