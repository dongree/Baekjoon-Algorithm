const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

const stack = [];
const answer = [];
let isWord = true;

for (let i = 0; i < s.length; i++) {
  if (isWord) {
    if (s[i] === '<') {
      isWord = false;
      while (stack.length !== 0) {
        answer.push(stack.pop());
      }
      answer.push(s[i]);
    } else if (s[i] === ' ') {
      while (stack.length !== 0) {
        answer.push(stack.pop());
      }
      answer.push(s[i]);
    } else {
      stack.push(s[i]);
    }
  } else {
    if (s[i] === '>') {
      isWord = true;
      answer.push(s[i]);
    } else {
      answer.push(s[i]);
    }
  }
}

while (stack.length !== 0) {
  answer.push(stack.pop());
}

console.log(answer.join(''));
