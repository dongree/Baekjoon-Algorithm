const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [l, c] = inputs[0].split(' ').map(Number);
const alphabets = inputs[1].split(' ').sort();
const answer = [];
const code = [];

dfs(0, 0);
console.log(answer.join('\n'));

function dfs(idx, cnt) {
  if (cnt === l) {
    const vowelLength = code.filter(
      (a) => a === 'a' || a === 'e' || a === 'i' || a === 'o' || a === 'u'
    ).length;
    if (0 < vowelLength && vowelLength <= l - 2) {
      answer.push(code.join(''));
    }
  }

  for (let i = idx; i < c; i++) {
    code.push(alphabets[i]);
    dfs(i + 1, cnt + 1);
    code.pop();
  }
}
