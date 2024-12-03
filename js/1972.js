const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const result = [];

for (let i = 0; i < inputs.length - 1; i++) {
  const s = inputs[i];

  if (isSuperstring(s)) {
    result.push(`${s} is surprising.`);
  } else {
    result.push(`${s} is NOT surprising.`);
  }
}

console.log(result.join('\n'));

function isSuperstring(s) {
  const n = s.length - 2;

  for (let i = 0; i <= n; i++) {
    let k = i + 1;
    const obj = {};

    for (let j = 0; j < s.length - k; j++) {
      const ns = s[j] + s[j + k];
      if (obj[ns] === undefined) obj[ns] = 1;
      else return false;
    }
  }
  return true;
}
