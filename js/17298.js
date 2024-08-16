const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1].split(' ').map(Number);

const stack = [];
const result = Array(N).fill(-1);

for (let i = 0; i < N; i++) {
  while (stack.length !== 0 && arr[i] > arr[stack[stack.length - 1]]) {
    result[stack[stack.length - 1]] = arr[i];
    stack.pop();
  }
  stack.push(i);
}

console.log(result.join(' '));
