const fs = require('fs');

const [T, ...arr] = fs.readFileSync('example.txt').toString().trim().split('\n');

const result = [];
for (let i = 0; i < arr.length; i++) {
  const s = arr[i];
  const obj = {};

  for (let j = 0; j < s.length; j++) {
    if (s[j] === ' ') continue;

    if (obj[s[j]] === undefined) obj[s[j]] = 1;
    else obj[s[j]] += 1;
  }

  const a = Object.entries(obj).sort((a, b) => b[1] - a[1]);
  if (a.length === 1 || a[0][1] !== a[1][1]) result.push(a[0][0]);
  else result.push('?');
}

console.log(result.join('\n'));
