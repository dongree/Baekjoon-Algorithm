const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

let [N, L, F] = getLine().split(' ');

const [D, T] = L.split('/');
const [h, m] = T.split(':');

const seconds = (Number(h) * 60 + Number(m) + Number(D) * 60 * 24) * 60 * 1000;

const dic = new Map();
const ans = new Map();

while (N--) {
  const [d, t, P, M] = getLine().split(' ');

  const key = P + '/' + M;
  const value = new Date(d + ' ' + t);

  if (dic.get(key) === undefined) {
    dic.set(key, value);
  } else {
    const preValue = dic.get(key);
    const gap = value - preValue;

    if (gap > seconds) {
      const cost = ((gap - seconds) / 60000) * F;
      if (ans.get(M) === undefined) ans.set(M, cost);
      else ans.set(M, ans.get(M) + cost);
    }
    dic.delete(key);
  }
}

console.log(
  ans.size === 0
    ? -1
    : [...ans]
        .sort()
        .map((e) => e.join(' '))
        .join('\n')
);
