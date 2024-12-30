const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const result = [];

for (let i = 0; i < inputs.length - 1; i++) {
  let s = inputs[i];

  while (s.length > 1) {
    let ss = 0;
    for (let j = 0; j < s.length; j++) {
      ss += +s[j];
    }
    s = ss.toString();
  }

  result.push(s);
}

console.log(result.join('\n'));
