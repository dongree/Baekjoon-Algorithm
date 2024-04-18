const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1].split(' ').map(Number);

const stack = [];
const ans = [];

for (let i = 0; i < N; i++) {
  if (stack.length === 0) ans.push(0);
  else {
    if (arr[stack[stack.length - 1] - 1] < arr[i]) {
      while (stack.length && arr[stack[stack.length - 1] - 1] < arr[i]) {
        stack.pop();
      }
      ans.push(stack.length === 0 ? 0 : stack[stack.length - 1]);
    } else {
      ans.push(stack[stack.length - 1]);
    }
  }
  stack.push(i + 1);
}

console.log(ans.join(' '));
