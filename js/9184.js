const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');
const memo = Array(101)
  .fill()
  .map(() =>
    Array(101)
      .fill()
      .map(() => Array(101).fill(null))
  );
let answer = [];

for (let i = 0; i < inputs.length - 1; i++) {
  const [a, b, c] = inputs[i].split(' ').map(Number);
  answer.push(`w(${a}, ${b}, ${c}) = ${w(a, b, c)}`);
}

console.log(answer.join('\n'));

function w(a, b, c) {
  if (memo[a + 50][b + 50][c + 50] !== null)
    return memo[a + 50][b + 50][c + 50];
  let result = 0;
  if (a <= 0 || b <= 0 || c <= 0) result = 1;
  else if (a > 20 || b > 20 || c > 20) result = w(20, 20, 20);
  else if (a < b && b < c)
    result = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
  else
    result =
      w(a - 1, b, c) +
      w(a - 1, b - 1, c) +
      w(a - 1, b, c - 1) -
      w(a - 1, b - 1, c - 1);
  memo[a + 50][b + 50][c + 50] = result;
  return result;
}
