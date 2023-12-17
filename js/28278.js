const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];
const commands = [];
const stack = [];
let result = '';

for (let i = 1; i <= n; i++) {
  commands.push(inputs[i]);
}

commands.forEach((command) => {
  switch (command[0]) {
    case '1':
      stack.push(command.substring(2));
      break;
    case '2':
      if (stack.length !== 0) {
        result += `${stack[stack.length - 1]}\n`;
        stack.pop();
      } else {
        result += `-1\n`;
      }
      break;
    case '3':
      result += `${stack.length}\n`;
      break;
    case '4':
      result += `${stack.length === 0 ? 1 : 0}\n`;
      break;
    case '5':
      result += `${stack.length !== 0 ? stack[stack.length - 1] : -1}\n`;
      break;
  }
});

console.log(result);
