const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];

const commands = [];
for (let i = 1; i <= n; i++) {
  commands.push(inputs[i].split(' '));
}

const queue = [];
let idx = 0;
let result = '';

commands.forEach((command) => {
  const length = queue.length - idx;
  switch (command[0]) {
    case 'push':
      queue.push(command[1]);
      break;
    case 'pop':
      if (length !== 0) {
        result += `${queue[idx]}\n`;
        idx++;
      } else {
        result += `-1\n`;
      }
      break;
    case 'size':
      result += `${length}\n`;
      break;
    case 'empty':
      result += `${length === 0 ? 1 : 0}\n`;
      break;
    case 'front':
      result += `${length === 0 ? -1 : queue[idx]}\n`;
      break;
    case 'back':
      result += `${length === 0 ? -1 : queue[queue.length - 1]}\n`;
      break;
  }
});

console.log(result);
