const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

let ans = 0;
const stack = [];

const N = inputs[0];

for (let i = 1; i <= N; i++) {
  while (stack.length > 0 && stack[stack.length - 1][0] <= inputs[i]) {
    const [_, j] = stack.pop();
    ans += i - j - 1;
  }
  stack.push([inputs[i], i]);
}

while (stack.length != 0) {
  const [_, j] = stack.pop();
  ans += N - j;
}

console.log(ans);
