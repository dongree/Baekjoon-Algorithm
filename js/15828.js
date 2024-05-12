const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

const N = inputs[0];

let idx = 0;
const q = [];

for (let i = 1; i <= inputs.length; i++) {
  if (inputs[i] > 0) {
    if (q.length < N + idx) q.push(inputs[i]);
  } else if (inputs[i] === 0) {
    idx++;
  } else if (inputs[i] === -1) {
    if (q.length === idx) console.log('empty');
    else {
      const ans = [];
      while (q.length !== idx) {
        ans.push(q[idx++]);
      }
      console.log(ans.join(' '));
    }
  }
}
