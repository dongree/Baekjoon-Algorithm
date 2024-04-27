const fs = require('fs');

let N = BigInt(fs.readFileSync('example.txt').toString().trim());
let s = 1n;
let result = 0n;

while (N !== 0n) {
  if (N & 1n) result += s;
  s *= 3n;
  N = N >> 1n;
}

console.log(result.toString());
