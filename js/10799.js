const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

const stack = [];
let ans = 0;

for (let i = 0; i < s.length; i++) {
  if (s[i] === '(' && s[i + 1] === ')') {
    ans += stack.length;
    i++;
  } else if (s[i] === '(') {
    stack.push(s[i]);
  } else {
    stack.pop();
    ans++;
  }
}

console.log(ans);
