const fs = require('fs');

const input = fs.readFileSync('/dev/stdin').toString().trim();
const map = new Map();
const n = input.length;

for (let i = 1; i <= n; i++) {
  for (let j = 0; j <= n - i; j++) {
    const item = input.substring(j, j + i);
    if (map.get(item) === undefined) {
      map.set(item, 1);
    }
  }
}

console.log(map.size);
