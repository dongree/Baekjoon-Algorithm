const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const t = +inputs[0];

for (let tc = 1; tc <= t; tc++) {
  const [x, y] = inputs[tc].split(' ').map(Number);
  let distance = y - x;
  let answer;

  const sqrtValue = Math.sqrt(distance);
  if (sqrtValue % 1 === 0) {
    answer = sqrtValue * 2 - 1;
  } else {
    const a = Math.ceil(sqrtValue);
    const top = a ** 2;
    const bottom = (a - 1) ** 2;
    const middle = bottom + (top - bottom - 1) / 2;

    if (distance <= middle) answer = a * 2 - 2;
    else answer = a * 2 - 1;
  }

  console.log(answer);
}
