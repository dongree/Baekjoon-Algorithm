const fs = require('fs');

const [T, ...arr] = fs.readFileSync('example.txt').toString().trim().split('\n');

const result = [];

for (let i = 0; i < arr.length; i++) {
  const len = arr[i].length;
  const n = +arr[i];

  const s = String(n * n);

  const k = s.substring(s.length - len);

  if (k === String(n)) result.push('YES');
  else result.push('NO');
}

console.log(result.join('\n'));
