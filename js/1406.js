const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const stack1 = getLine().split('');
const stack2 = [];

let M = +getLine();

while (M--) {
  const command = getLine();
  switch (command[0]) {
    case 'L': {
      if (stack1.length === 0) continue;
      stack2.push(stack1.pop());
      break;
    }
    case 'D': {
      if (stack2.length === 0) continue;
      stack1.push(stack2.pop());
      break;
    }
    case 'B': {
      if (stack1.length === 0) continue;
      stack1.pop();
      break;
    }
    case 'P': {
      stack1.push(command[2]);
      break;
    }
  }
}

const result = [...stack1, ...stack2.reverse()].join('');
console.log(result);
// console.log(stack1);
// console.log(stack2);
