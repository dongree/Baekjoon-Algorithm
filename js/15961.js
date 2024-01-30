const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, d, k, c] = inputs[0].split(' ').map(Number);
const sushi = inputs.slice(1).map(Number);
const hasSushi = Array(d + 1).fill(0);

let cnt = 0;
for (let i = 0; i < k; i++) {
  if (hasSushi[sushi[i]] === 0) cnt++;
  hasSushi[sushi[i]]++;
}
let answer = hasSushi[c] ? cnt : cnt + 1;

for (let i = 0; i < N; i++) {
  if (hasSushi[sushi[i]] === 1) cnt--;
  hasSushi[sushi[i]]--;
  if (hasSushi[sushi[(i + k) % N]] === 0) cnt++;
  hasSushi[sushi[(i + k) % N]]++;
  answer = Math.max(answer, hasSushi[c] ? cnt : cnt + 1);
}

console.log(answer);
