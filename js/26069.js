const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];

const dic = new Map();
dic.set('ChongChong', true);

for (let i = 1; i <= N; i++) {
  const [a, b] = inputs[i].split(' ');

  if (dic.get(a)) dic.set(b, true);
  if (dic.get(b)) dic.set(a, true);
}

console.log(dic.size);
