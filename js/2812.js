const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let [N, K] = inputs[0].split(' ').map(Number);
const s = inputs[1];

const stack = [];

for (let i = 0; i < s.length; i++) {
  if (stack.length === 0) stack.push(s[i]);
  else {
    while (K !== 0 && stack[stack.length - 1] < s[i]) {
      stack.pop();
      K--;
    }
    stack.push(s[i]);
  }
}

console.log(K);

while (K !== 0) {
  stack.pop();
  K--;
}

console.log(stack.join(''));
