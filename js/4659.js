const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const ans = [];

for (let i = 0; i < inputs.length - 1; i++) {
  const s = inputs[i];

  if (check(s)) {
    ans.push(`<${s}> is acceptable.`);
  } else {
    ans.push(`<${s}> is not acceptable.`);
  }
}

console.log(ans.join('\n'));

function check(s) {
  let includedVowel = false;
  let pre = '';
  let continueCount = 0;
  let isVowel = false;

  for (let i = 0; i < s.length; i++) {
    if (
      s[i] === 'a' ||
      s[i] === 'e' ||
      s[i] === 'i' ||
      s[i] === 'o' ||
      s[i] === 'u'
    ) {
      includedVowel = true;
      if (isVowel) continueCount++;
      else continueCount = 1;
      isVowel = true;
    } else {
      if (!isVowel) continueCount++;
      else continueCount = 1;
      isVowel = false;
    }

    if (s[i] === pre && s[i] !== 'e' && s[i] !== 'o') return false;
    if (continueCount >= 3) return false;
    pre = s[i];
  }

  if (includedVowel) return true;
  else return false;
}
