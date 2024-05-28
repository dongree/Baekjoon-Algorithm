const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const T = +inputs[0];
const ans = [];

for (let i = 1; i <= T; i++) {
  const s = inputs[i];
  const a = checkPalindrome1(s);
  const b = checkPalindrome2(s);

  if (a === 1 || b === 1) ans.push(1);
  else ans.push(a);
}

console.log(ans.join('\n'));

function checkPalindrome1(s) {
  let isPseudo = false;

  let start = 0;
  let end = s.length - 1;

  while (start <= end) {
    if (s[start] === s[end]) {
      start++;
      end--;
      continue;
    }

    if (!isPseudo && start + 1 <= end && s[start + 1] === s[end]) {
      start++;
      isPseudo = true;
      continue;
    }

    if (!isPseudo && start <= end - 1 && s[start] === s[end - 1]) {
      end--;
      isPseudo = true;
      continue;
    }

    return 2;
  }
  if (isPseudo) return 1;
  else return 0;
}

function checkPalindrome2(s) {
  let isPseudo = false;

  let start = 0;
  let end = s.length - 1;

  while (start <= end) {
    if (s[start] === s[end]) {
      start++;
      end--;
      continue;
    }

    if (!isPseudo && start <= end - 1 && s[start] === s[end - 1]) {
      end--;
      isPseudo = true;
      continue;
    }

    if (!isPseudo && start + 1 <= end && s[start + 1] === s[end]) {
      start++;
      isPseudo = true;
      continue;
    }

    return 2;
  }
  if (isPseudo) return 1;
  else return 0;
}
