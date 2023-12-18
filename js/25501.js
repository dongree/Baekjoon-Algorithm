const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const t = +inputs[0];
const cases = [];

for (let i = 1; i <= t; i++) {
  cases.push(inputs[i]);
}

cases.forEach((c) => {
  console.log(isPalindromeAndRecursionCount(c).join(' '));
});

function isPalindromeAndRecursionCount(s) {
  function recursion(s, l, r, cnt) {
    if (l >= r) return [1, cnt];
    else if (s[l] !== s[r]) return [0, cnt];
    else return recursion(s, l + 1, r - 1, cnt + 1);
  }

  return recursion(s, 0, s.length - 1, 1);
}
