const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];

const [M, N] = getLine();

const arr = [];

for (let i = 0; i < M; i++) {
  const a = getLine();
  const nas = getString([...a]);

  arr.push(nas);
}

let ans = 0;

for (let i = 0; i < M - 1; i++) {
  for (let j = i + 1; j < M; j++) {
    if (arr[i] === arr[j]) ans++;
  }
}

console.log(ans);

function getString(arr) {
  let idx = 1;
  const dic = {};

  const temp = [...arr];

  arr.sort((a, b) => a - b);
  arr.forEach((e) => {
    dic[e] = idx++;
  });

  const result = temp.map((e) => dic[e]);
  return result.join('');
}
