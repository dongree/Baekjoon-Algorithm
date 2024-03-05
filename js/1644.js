const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString();

const isPrime = Array(N + 1).fill(true);
const pn = [];

for (let i = 2; i * i <= N; i++) {
  if (isPrime[i]) {
    for (let j = i * i; j <= N; j += i) {
      isPrime[j] = false;
    }
  }
}

for (let i = 2; i <= N; i++) {
  if (isPrime[i]) pn.push(i);
}

let p1 = 0;
let p2 = 0;
let sum = 2;
let answer = 0;

while (p2 <= p1 && p1 < pn.length) {
  if (sum >= N) {
    if (sum === N) answer++;
    sum -= pn[p2++];
  } else {
    sum += pn[++p1];
  }
}

console.log(answer);
