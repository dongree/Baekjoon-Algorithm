const fs = require('fs');

const [N, P, Q] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

const dic = new Map();

const ans = recur(N);
console.log(ans);

function recur(i) {
  if (i === 0) return 1;
  const ip = Math.floor(i / P);
  const iq = Math.floor(i / Q);

  if (dic[i]) return dic[i];
  else return (dic[i] = recur(ip) + recur(iq));
}
