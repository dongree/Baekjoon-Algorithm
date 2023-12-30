const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, d, k, c] = inputs[0].split(' ').map(Number);
const belt = [];
const check = Array(d + 1).fill(0);
let cnt = 0;
let answer = 0;

for (let i = 1; i <= n; i++) {
  belt.push(+inputs[i]);
}

for (let i = 0; i < k; i++) {
  if (check[belt[i]] === 0) {
    cnt++;
  }
  check[belt[i]]++;
}

for (let i = 0; i < n; i++) {
  if (i !== 0) {
    check[belt[(i - 1) % n]]--;
    if (check[belt[(i - 1) % n]] === 0) cnt--;
    if (check[belt[(i + k - 1) % n]] === 0) cnt++;
    check[belt[(i + k - 1) % n]]++;
  }

  answer = Math.max(answer, check[c] === 0 ? cnt + 1 : cnt);
}

console.log(answer);
