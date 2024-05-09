const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const dic = new Map();

for (let i = 1; i <= N; i++) {
  const [_, ext] = inputs[i].split('.');

  if (!dic.has(ext)) {
    dic.set(ext, 1);
  } else {
    dic.set(ext, dic.get(ext) + 1);
  }
}

const ans = [...dic.entries()]
  .sort()
  .map((e) => e.join(' '))
  .join('\n');

console.log(ans);
