const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const ans = [];
inputs.forEach((input) => {
  const [s, t] = input.split(' ');

  let idx = 0;

  for (let i = 0; i < t.length; i++) {
    if (t[i] === s[idx]) idx++;
  }

  ans.push(idx === s.length ? 'Yes' : 'No');
});

console.log(ans.join('\n'));
