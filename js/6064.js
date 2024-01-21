const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const T = +inputs[0];
const answer = [];

for (let i = 1; i <= T; i++) {
  let [M, N, x, y] = inputs[i].split(' ').map(Number);

  const lcm = (M * N) / gcd(M, N);

  while (true) {
    if (x > lcm || y > lcm) {
      answer.push(-1);
      break;
    } else if (x > y) y += N;
    else if (x < y) x += M;
    else {
      answer.push(x);
      break;
    }
  }
}

console.log(answer.join('\n'));

function gcd(a, b) {
  if (a % b === 0) return b;
  else return gcd(b, a % b);
}
