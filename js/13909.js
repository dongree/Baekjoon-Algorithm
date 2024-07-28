const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString().trim();

for (let i = 1; i < 100000; i++) {
  if (N < (i + 1) * (i + 1)) {
    console.log(i);
    break;
  }
}
