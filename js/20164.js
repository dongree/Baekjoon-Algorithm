const fs = require('fs');

const N = fs.readFileSync('example.txt').toString().trim();

let minV = Infinity;
let maxV = -Infinity;

dfs(N, 0);

console.log(minV, maxV);

function dfs(s, cnt) {
  const sn = s.length;

  let nCnt = cnt;
  for (let i = 0; i < sn; i++) {
    if (Number(s[i]) % 2 === 1) nCnt++;
  }

  if (sn === 1) {
    minV = Math.min(minV, nCnt);
    maxV = Math.max(maxV, nCnt);
    return;
  } else if (sn === 2) {
    const newS = (Number(s[0]) + Number(s[1])).toString();

    dfs(newS, nCnt);
  } else if (sn >= 3) {
    for (let i = 0; i < sn - 1; i++) {
      for (let j = i + 1; j < sn - 1; j++) {
        const a = +s.substring(0, i + 1);
        const b = +s.substring(i + 1, j + 1);
        const c = +s.substring(j + 1);
        const newS = (a + b + c).toString();
        dfs(newS, nCnt);
      }
    }
  }
}
