const fs = require('fs');

const [T, ...arr] = fs.readFileSync('example.txt').toString().trim().split('\n').map(Number);

const isPrime = Array(1_000_001).fill(true);
isPrime[0] = false;
isPrime[1] = false;

for (let i = 2; i * i <= 1_000_000; i++) {
  if (!isPrime[i]) continue;
  for (let j = i * i; j <= 1_000_000; j += i) {
    isPrime[j] = false;
  }
}

const result = [];

arr.forEach((e) => {
  let cnt = 0;

  for (let i = 2; i <= e / 2; i++) {
    if (isPrime[i] && isPrime[e - i]) cnt++;
  }

  result.push(cnt);
});

console.log(result.join('\n'));
