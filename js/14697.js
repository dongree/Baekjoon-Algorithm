const fs = require('fs');

const [A, B, C, N] = fs.readFileSync('example.txt').toString().trim().split(' ').map(Number);

console.log(check());

function check() {
  const a = Math.floor(N / A);

  for (let i = 0; i <= a; i++) {
    const b = Math.floor((N - A * i) / B);
    for (let j = 0; j <= b; j++) {
      const c = Math.floor(N - A * i - B * j);
      if (c % C === 0) {
        return 1;
      }
    }
  }

  return 0;
}
