const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString().trim();

let k = N;
while (true) {
  if (isPrime(k) && isPellindrom(k)) {
    console.log(k);
    break;
  }
  k++;
}

function isPellindrom(n) {
  const s = n.toString();

  let start = 0;
  let end = s.length - 1;

  while (start < end) {
    if (s[start] !== s[end]) return false;
    start++;
    end--;
  }

  return true;
}

function isPrime(n) {
  if (n === 1) return false;
  for (let i = 2; i * i <= n; i++) {
    if (n % i === 0) return false;
  }
  return true;
}
