const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];

const obj = {};
let cnt = 0;

for (let i = 1; i <= N; i++) {
  const [a, b] = inputs[i].split(' ').map(Number);

  if (obj[a] === undefined) obj[a] = b;
  else {
    if (obj[a] !== b) {
      obj[a] = b;
      cnt++;
    }
  }
}

console.log(cnt);
