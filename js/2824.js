const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const A = inputs[1]
  .split(' ')
  .map(BigInt)
  .reduce((a, b) => a * b, 1n);

const B = inputs[3]
  .split(' ')
  .map(BigInt)
  .reduce((a, b) => a * b, 1n);

const result = gcd(A, B).toString();
const n = result.length;

console.log(n > 9 ? result.substring(n - 9) : result);

function gcd(a, b) {
  if (a % b === 0n) return b;
  return gcd(b, a % b);
}
