const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

const arr = Array(26).fill(0);

for (let i = 0; i < s.length; i++) {
  const idx = s[i].charCodeAt(0) - 'A'.charCodeAt(0);
  arr[idx]++;
}

if (isPossible()) {
  let k = null;
  let ss = '';

  for (let i = 0; i < 26; i++) {
    const a = String.fromCharCode('A'.charCodeAt(0) + i);
    if (arr[i] === 0) continue;

    if (arr[i] % 2 === 1) {
      if (arr[i] > 1) ss += a.repeat(Math.floor(arr[i] / 2));
      k = a;
    } else {
      ss += a.repeat(arr[i] / 2);
    }
  }

  if (k === null) console.log(ss + ss.split('').reverse().join(''));
  else console.log(ss + k + ss.split('').reverse().join(''));
} else console.log("I'm Sorry Hansoo");

function isPossible() {
  let cnt = 0;

  for (let i = 0; i < 26; i++) {
    if (arr[i] === 0) continue;

    if (arr[i] % 2 === 1) cnt++;
    if (cnt >= 2) return false;
  }
  return true;
}
