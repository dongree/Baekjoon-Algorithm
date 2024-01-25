const fs = require('fs');

const [A, B, C] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split(' ')
  .map(BigInt);

console.log(solve(B).toString());

function solve(power) {
  if (power === 1n) return A % C;

  const half = solve(power / 2n) % C;

  if (power % 2n === 1n) return (half * half * (A % C)) % C;
  else return (half * half) % C;
}
