const fs = require('fs');

const [N, M] = fs.readFileSync('example.txt').toString().trim().split(' ').map(Number);

if (N < M || (N + M) % 2 !== 0 || (N - M) % 2 !== 0) {
  console.log(-1);
} else {
  console.log((N + M) / 2, (N - M) / 2);
}
