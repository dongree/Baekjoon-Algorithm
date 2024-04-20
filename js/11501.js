const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];

let [T] = getLine();

const answer = [];

while (T--) {
  const [N] = getLine();
  const arr = getLine();
  let ans = 0;
  let maxV = 0;

  for (let i = N - 1; i >= 0; i--) {
    if (arr[i] > maxV) maxV = arr[i];
    else if (arr[i] < maxV) ans += maxV - arr[i];
  }

  answer.push(ans);
}

console.log(answer.join('\n'));
