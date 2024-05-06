const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let s = inputs[0];
const bombS = inputs[1];
const stack = [];

for (let i = 0; i < s.length; i++) {
  if (s[i] === bombS[bombS.length - 1]) {
    let flag = false;
    for (let j = 0; j < bombS.length - 1; j++) {
      if (stack[stack.length - bombS.length + 1 + j] !== bombS[j]) {
        flag = true;
        break;
      }
    }

    if (flag) {
      stack.push(s[i]);
    } else {
      for (let j = 0; j < bombS.length - 1; j++) {
        stack.pop();
      }
    }
  } else {
    stack.push(s[i]);
  }
}

console.log(stack.length === 0 ? 'FRULA' : stack.join(''));
