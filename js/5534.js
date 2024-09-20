const fs = require('fs');

const [N, s, ...arr] = fs.readFileSync('example.txt').toString().trim().split('\n');

let cnt = 0;
const sLength = s.length;

for (let i = 0; i < arr.length; i++) {
  const ns = arr[i];
  const nsLength = ns.length;

  let flag = false;
  a: for (let j = 0; j < nsLength; j++) {
    for (let gap = 1; gap < nsLength; gap++) {
      if (j + (sLength - 1) * gap > nsLength - 1) {
        break;
      }

      let isPossible = true;
      for (let k = 0; k < sLength; k++) {
        if (s[k] !== ns[j + k * gap]) {
          isPossible = false;
          break;
        }
      }
      if (isPossible) {
        flag = true;
        break a;
      }
    }
  }

  if (flag) {
    cnt++;
  }
}

console.log(cnt);
