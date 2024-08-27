const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const s = inputs[1];

let cnt1 = 0;
let cnt2 = 0;

for (let i = 0; i < N; i++) {
  if (s[i] === 'e') cnt1++;
  else cnt2++;
}

if (cnt1 > cnt2) console.log('e');
else if (cnt1 < cnt2) console.log('2');
else console.log('yee');
