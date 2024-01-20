const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const n = +inputs[0];
const arr = [];

if (n == 0) {
  console.log(0);
} else {
  for (let i = 1; i <= n; i++) {
    arr.push(+inputs[i]);
  }
  arr.sort((a, b) => a - b);

  const excludedNum = Math.round(n * 0.15);

  const answer = Math.round(
    arr.slice(excludedNum, n - excludedNum).reduce((a, b) => a + b, 0) /
      (n - 2 * excludedNum)
  );

  console.log(answer);
}
