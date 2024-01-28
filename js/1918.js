const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

const stack = [];
let answer = '';

for (let i = 0; i < s.length; i++) {
  if ('A' <= s[i] && s[i] <= 'Z') answer += s[i];
  else if (s[i] === '(') stack.push(s[i]);
  else if (s[i] === ')') {
    while (stack.length && stack[stack.length - 1] !== '(') {
      answer += stack.pop();
    }
    stack.pop();
  } else if (s[i] === '+' || s[i] === '-') {
    while (stack.length && stack[stack.length - 1] !== '(') {
      answer += stack.pop();
    }
    stack.push(s[i]);
  } else if (s[i] === '*' || s[i] === '/') {
    while (
      stack.length &&
      (stack[stack.length - 1] === '*' || stack[stack.length - 1] === '/')
    ) {
      answer += stack.pop();
    }
    stack.push(s[i]);
  }
}
while (stack.length) {
  answer += stack.pop();
}

console.log(answer);
