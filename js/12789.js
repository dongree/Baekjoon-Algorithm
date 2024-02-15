const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1].split(' ').map(Number);
const stack = [];

let target = 1;

let i = 0;
while (i < N) {
  if (stack.length !== 0 && stack[stack.length - 1] === target) {
    stack.pop();
    target++;
  } else if (arr[i] !== target) {
    stack.push(arr[i++]);
  } else if (arr[i] === target) {
    target++;
    i++;
  }
}

const bool =
  stack.length === 0 ||
  stack.length === 1 ||
  stack.every((_, idx) => {
    if (idx === stack.length - 1) return true;
    return stack[idx] > stack[idx + 1];
  });

if (bool) console.log('Nice');
else console.log('Sad');
