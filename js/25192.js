const fs = require('fs');

const [N, ...arr] = fs.readFileSync('example.txt').toString().trim().split('\n');

const dic = new Map();
let cnt = 0;

for (let i = 0; i < +N; i++) {
  const s = arr[i];

  if (s === 'ENTER') {
    dic.clear();
    continue;
  }

  if (!dic.has(s)) {
    cnt++;
    dic.set(s, true);
  }
}

console.log(cnt);
