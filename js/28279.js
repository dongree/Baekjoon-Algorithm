const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];
const commands = [];
const frontDeque = [];
const backDeque = [];
let result = [];

let backIdx = 0;
let frontIdx = 0;

for (let i = 1; i <= n; i++) {
  commands.push(inputs[i]);
}

commands.forEach((command) => {
  const length = backDeque.length + frontDeque.length - backIdx - frontIdx;
  switch (command[0]) {
    case '1':
      frontDeque.push(command.substring(2));
      break;
    case '2':
      backDeque.push(command.substring(2));
      break;
    case '3':
      if (length !== 0) {
        if (frontDeque.length - frontIdx !== 0) {
          result.push(frontDeque[frontDeque.length - 1]);
          frontDeque.pop();
        } else {
          result.push(backDeque[backIdx]);
          backIdx++;
        }
      } else {
        result.push(-1);
      }
      break;
    case '4':
      if (length !== 0) {
        if (backDeque.length - backIdx !== 0) {
          result.push(backDeque[backDeque.length - 1]);
          backDeque.pop();
        } else {
          result.push(frontDeque[frontIdx]);
          frontIdx++;
        }
      } else {
        result.push(-1);
      }
      break;
    case '5':
      result.push(length);
      break;
    case '6':
      result.push(length === 0 ? 1 : 0);
      break;
    case '7':
      if (length !== 0) {
        if (frontDeque.length - frontIdx !== 0) {
          result.push(frontDeque[frontDeque.length - 1]);
        } else {
          result.push(backDeque[backIdx]);
        }
      } else {
        result.push(-1);
      }
      break;
    case '8':
      if (length !== 0) {
        if (backDeque.length - backIdx !== 0) {
          result.push(backDeque[backDeque.length - 1]);
        } else {
          result.push(frontDeque[frontIdx]);
        }
      } else {
        result.push(-1);
      }
      break;
  }
});

console.log(result.join('\n'));
