const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const t = +inputs[0];
const answer = [];

for (let tc = 1; tc < t * 3; tc += 3) {
  const p = inputs[tc].split('');
  const n = +inputs[tc + 1];
  const arr = JSON.parse(inputs[tc + 2]);

  let isFlip = false;
  let start = 0;
  let end = n;
  p.forEach((command) => {
    if (command === 'R') isFlip = !isFlip;
    else {
      if (isFlip) end--;
      else start++;
    }
  });

  if (start > end) {
    answer.push('error');
  } else {
    const temp = [];
    for (let i = 0; i < end - start; i++) {
      temp.push(isFlip ? arr[end - 1 - i] : arr[start + i]);
    }
    answer.push(`[${temp.toString()}]`);
  }
}

console.log(answer.join('\n'));
