const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const T = +inputs[0];

const answer = [];

for (let i = 1; i < T * 2; i += 2) {
  const N = inputs[i];
  const mbtis = inputs[i + 1].split(' ');

  if (N > 32) {
    answer.push(0);
    continue;
  }

  const selected = [];
  let minDist = 20;

  dfs(0, 0);
  answer.push(minDist);

  function dfs(idx, cnt) {
    if (cnt === 3) {
      let dist = 0;
      for (let i = 0; i < 4; i++) {
        if (selected[0][i] !== selected[1][i]) dist++;
        if (selected[0][i] !== selected[2][i]) dist++;
        if (selected[1][i] !== selected[2][i]) dist++;
      }
      minDist = Math.min(minDist, dist);
      return;
    }
    for (let i = idx; i < mbtis.length; i++) {
      selected.push(mbtis[i]);
      dfs(i + 1, cnt + 1);
      selected.pop();
    }
  }
}

console.log(answer.join('\n'));
