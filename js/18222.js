const fs = require('fs');

const k = BigInt(fs.readFileSync('example.txt').toString().trim());

console.log(dc(k - 1n));

function dc(idx) {
  if (idx === 0n) return 0;
  if (idx % 2n === 0n) return dc(idx / 2n);
  else return 1 - dc(idx / 2n);
}
