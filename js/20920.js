const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);
const arr = [];
const dic = {};

for (let i = 1; i <= N; i++) {
  if (dic[inputs[i]] === undefined) {
    if (inputs[i].length >= M) arr.push(inputs[i]);
    dic[inputs[i]] = 1;
  } else {
    dic[inputs[i]]++;
  }
}

const sorted = arr.sort((a, b) => {
  if (dic[a] === dic[b]) {
    if (a.length === b.length) {
      if (a < b) return -1;
      if (a > b) return 1;
      return 0;
    }
    return b.length - a.length;
  }
  return dic[b] - dic[a];
});

console.log(sorted.join('\n'));
