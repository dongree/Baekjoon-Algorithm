const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const S = getLine();
const n = S.length;

const arr = Array(26)
  .fill()
  .map(() => Array(n + 1).fill(0));

for (let i = 0; i < n; i++) {
  const an = S[i].charCodeAt(0) - 'a'.charCodeAt(0);
  arr[an][i + 1] += 1;
}

for (let i = 0; i < 26; i++) {
  for (let j = 1; j <= n; j++) {
    arr[i][j] = arr[i][j] + arr[i][j - 1];
  }
}

let q = +getLine();
const answer = [];

while (q--) {
  const [a, l, r] = getLine().split(' ');
  const an = a.charCodeAt(0) - 'a'.charCodeAt(0);
  answer.push(arr[an][+r + 1] - arr[an][+l]);
}

console.log(answer.join('\n'));
