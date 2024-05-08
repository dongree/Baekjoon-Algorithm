const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .sort();

const n = inputs.length;

const dic = new Map();

inputs.forEach((e) => {
  if (dic.get(e) === undefined) {
    dic.set(e, 1);
  } else {
    dic.set(e, dic.get(e) + 1);
  }
});

const ans = [...dic.entries()]
  .map((e) => {
    const arr = [...e];
    arr[1] = ((arr[1] / n) * 100).toFixed(4);
    return arr.join(' ');
  })
  .join('\n')
  .trim();

console.log(ans);
