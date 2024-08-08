const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split(' ');

const first = inputs[0];
const result = [];

for (let i = 1; i < inputs.length; i++) {
  const s = inputs[i];
  let newS = '';
  let name = '';

  let flag = false;
  for (let j = 0; j < s.length; j++) {
    if (s[j] === '*' || s[j] === '&') {
      if (flag) newS = s[j] + newS;
      else newS += s[j];
    } else if (s[j] === '[') {
      if (flag) newS = '[]' + newS;
      else newS += '[]';
      j++;
    } else if (s[j] === ',' || s[j] === ';') break;
    else {
      name += s[j];
      flag = true;
    }
  }

  result.push(first + newS + ' ' + name + ';');
}

console.log(result.join('\n'));
