const fs = require('fs');

const [K, L] = fs.readFileSync('example.txt').toString().trim().split(' ').map(BigInt);

let flag = true;

for (let i = 2n; i < L; i++) {
  if (K % i === 0n) {
    console.log('BAD', i.toString());
    flag = false;
    break;
  }
}

if (flag) console.log('GOOD');
