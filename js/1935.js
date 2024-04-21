const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const dic = {};
const N = +inputs[0];
const s = inputs[1];
const stack = [];

for (let i = 0; i < N; i++) {
  const a = String.fromCharCode('A'.charCodeAt(0) + i);
  dic[a] = +inputs[i + 2];
}

for (let i = 0; i < s.length; i++) {
  if (s[i] === '*' || s[i] === '+' || s[i] === '/' || s[i] === '-') {
    const a = stack.pop();
    const b = stack.pop();
    let result;

    if (s[i] === '*') result = a * b;
    else if (s[i] === '+') result = a + b;
    else if (s[i] === '/') result = b / a;
    else if (s[i] === '-') result = b - a;

    stack.push(result);
  } else {
    stack.push(dic[s[i]]);
  }
}

console.log(stack[0].toFixed(2));
