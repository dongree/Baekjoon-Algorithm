const fs = require('fs');

const [A, B, C, M] = fs.readFileSync('example.txt').toString().trim().split(' ').map(Number);

let HP = 0;
let work = 0;

for (let i = 0; i < 24; i++) {
  if (HP + A > M) {
    HP = HP - C < 0 ? 0 : HP - C;
  } else {
    HP += A;
    work += B;
  }
}

console.log(work);
