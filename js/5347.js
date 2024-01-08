const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().split('\n');

const n = +inputs[0];
const answer = [];
for (let i = 1; i <= n; i++) {
  const [a, b] = inputs[i].split(' ').map(Number);
  answer.push(lcm(a, b));
}

console.log(answer.join('\n'));

function gcd(a, b) {
  return a % b === 0 ? b : gcd(b, a % b);
}

function lcm(a, b) {
  return (a * b) / gcd(a, b);
}
