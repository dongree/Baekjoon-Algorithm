const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [a1, a2] = inputs[0].split(' ').map(Number);
const [b1, b2] = inputs[1].split(' ').map(Number);

const result1 = a1 * b2 + a2 * b1;
const result2 = a2 * b2;
const gcdValue = gcd(result1, result2);

console.log(result1 / gcdValue, result2 / gcdValue);

function gcd(a, b) {
  if (a % b === 0) return b;
  else return gcd(b, a % b);
}
