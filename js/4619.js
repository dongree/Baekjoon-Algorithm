const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const ans = [];

for (let i = 0; i < inputs.length - 1; i++) {
  const [B, N] = inputs[i];

  let gap = Infinity;
  let result = 0;

  for (let a = 1; a <= 1000000; a++) {
    const currGap = Math.abs(B - a ** N);

    if (currGap < gap) {
      result = a;
      gap = currGap;
    } else break;
  }
  ans.push(result);
}

console.log(ans.join('\n'));
