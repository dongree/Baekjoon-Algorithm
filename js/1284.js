const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const result = [];

for (let i = 0; i < inputs.length; i++) {
  if (inputs[i] === '0') break;

  let w = inputs[i].length + 1;

  w += inputs[i]
    .split('')
    .map((e) => {
      if (e === '1') return 2;
      else if (e === '0') return 4;
      else return 3;
    })
    .reduce((a, b) => a + b);

  result.push(w);
}

console.log(result.join('\n'));
