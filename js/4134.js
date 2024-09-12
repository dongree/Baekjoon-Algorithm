const fs = require('fs');

const [T, ...arr] = fs.readFileSync('example.txt').toString().trim().split('\n').map(Number);

const result = [];

arr.forEach((n) => {
  while (!isPrime(n)) n++;
  result.push(n);
});

console.log(result.join('\n'));

function isPrime(n) {
  if (n < 2) return false;
  for (let i = 2; i * i <= n; i++) {
    if (n % i === 0) return false;
  }
  return true;
}
