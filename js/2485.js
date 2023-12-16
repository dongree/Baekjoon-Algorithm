const fs = require('fs');

const inputs = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

const n = inputs[0];
const arr = [];
for (let i = 1; i <= n; i++) {
  arr.push(inputs[i]);
}

let gcdValue = arr[1] - arr[0];
const dists = [gcdValue];
for (let i = 2; i < n; i++) {
  const dist = arr[i] - arr[i - 1];
  dists.push(dist);
  gcdValue = gcd(gcdValue, dist);
}

const result = dists.reduce((prev, curr) => prev + curr / gcdValue - 1, 0);

console.log(result);

function gcd(a, b) {
  if (a % b === 0) return b;
  else return gcd(b, a % b);
}
