const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const S = inputs[0];
const T = inputs[1];
let flag = false;

dfs(T);

console.log(flag ? 1 : 0);

function dfs(s) {
  if (s === S) {
    flag = true;
    return;
  }

  if (s.length < S.length) {
    return;
  }

  console.log(s);

  if (s[s.length - 1] === 'A') {
    dfs(s.slice(0, s.length - 1));
  }

  if (s[0] === 'B') {
    let k = '';
    for (let i = 0; i < s.length; i++) {
      k = s[i] + k;
    }
    dfs(k.slice(0, k.length - 1));
  }
}
