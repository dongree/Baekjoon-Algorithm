const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

let T = +getLine();
const ans = [];

while (T--) {
  const N = +getLine();
  const arr = Array(N)
    .fill()
    .map(() => getLine())
    .sort();

  let preL = 0;
  let a = 'YES';

  for (let i = 0; i < arr.length; i++) {
    if (arr[i].slice(0, preL) === arr[i - 1]) {
      a = 'NO';
      break;
    }
    preL = arr[i].length;
  }
  ans.push(a);
}

console.log(ans.join('\n'));
