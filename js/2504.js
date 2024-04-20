const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

const stack = [];

let sum = 0;
let num = 1;

let isRight = true;

for (let i = 0; i < s.length; i++) {
  if (s[i] === '(') {
    stack.push(s[i]);
    num *= 2;
  } else if (s[i] === '[') {
    stack.push(s[i]);
    num *= 3;
  } else if (s[i] === ')') {
    if (stack.length === 0 || stack[stack.length - 1] !== '(') {
      isRight = false;
      break;
    }
    if (s[i - 1] === '(') sum += num;
    stack.pop();
    num /= 2;
  } else if (s[i] === ']') {
    if (stack.length === 0 || stack[stack.length - 1] !== '[') {
      isRight = false;
      break;
    }
    if (s[i - 1] === '[') sum += num;
    stack.pop();
    num /= 3;
  }
}

if (stack.length !== 0) isRight = false;

console.log(isRight ? sum : 0);
