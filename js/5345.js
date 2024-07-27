const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];

const result = [];

for (let i = 1; i <= N; i++) {
  const s = inputs[i];

  let p = false;
  let l = false;
  let cnt = 0;

  for (let i = 0; i < s.length; i++) {
    let c = s[i].toLowerCase();

    if (c === 'p') p = true;
    else if (p && c === 'l') l = true;
    else if (l && c === 'u') {
      cnt++;
      p = false;
      l = false;
    }
  }

  result.push(cnt);
}

console.log(result.join('\n'));
