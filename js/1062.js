const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');
let [N, K] = inputs[0].split(' ').map(Number);
const isVisited = Array(26).fill(false);

console.log(solve());

function solve() {
  K -= 5;

  if (K < 0) return 0;

  for (e of ['a', 'n', 't', 'i', 'c']) {
    isVisited[e.charCodeAt(0) - 'a'.charCodeAt(0)] = true;
  }

  const ns = new Set();
  const arr = [];
  let ans = 0;

  for (let i = 1; i <= N; i++) {
    const s = inputs[i].substring(4).slice(0, -4);
    arr.push(s);
    for (let j = 0; j < s.length; j++) {
      const k = s[j].charCodeAt(0) - 'a'.charCodeAt(0);
      if (isVisited[k]) continue;
      ns.add(k);
    }
  }

  const candi = [...ns];
  K = Math.min(K, candi.length);

  dfs(0, 0);

  return ans;

  function dfs(cnt, idx) {
    if (cnt === K) {
      let c = 0;
      arr.forEach((s) => {
        c++;
        for (let i = 0; i < s.length; i++) {
          if (!isVisited[s[i].charCodeAt(0) - 'a'.charCodeAt(0)]) {
            c--;
            break;
          }
        }
      });

      ans = Math.max(ans, c);
      return;
    }
    for (let i = idx; i < candi.length; i++) {
      isVisited[candi[i]] = true;
      dfs(cnt + 1, i + 1);
      isVisited[candi[i]] = false;
    }
  }
}
