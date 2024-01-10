const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const t = inputs[0];
let answer = '';

for (let i = 1; i <= t * 2; i += 2) {
  const w = inputs[i];
  const k = +inputs[i + 1];
  const map = new Map();

  for (let j = 0; j < w.length; j++) {
    if (!map.has(w[j])) map.set(w[j], [j]);
    else map.set(w[j], [...map.get(w[j]), j]);
  }

  const arr = [...map.values()];

  let min = Infinity;
  let max = -Infinity;

  for (let m = 0; m < arr.length; m++) {
    if (arr[m].length < k) continue;
    for (let n = k - 1; n < arr[m].length; n++) {
      min = Math.min(min, arr[m][n] - arr[m][n - k + 1] + 1);
      max = Math.max(max, arr[m][n] - arr[m][n - k + 1] + 1);
    }
  }

  if (min === Infinity) answer += -1 + '\n';
  else answer += min + ' ' + max + '\n';
}

console.log(answer);
