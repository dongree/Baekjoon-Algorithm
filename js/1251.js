const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

const n = s.length;
const arr = [];

for (let i = 1; i < n; i++) {
  for (let j = i + 1; j < n; j++) {
    const word = makeWord(i, j);
    arr.push(word);
  }
}

arr.sort();
console.log(arr[0]);

function makeWord(i, j) {
  const a = s.substring(0, i).split('').reverse().join('');
  const b = s.substring(i, j).split('').reverse().join('');
  const c = s.substring(j).split('').reverse().join('');

  return a + b + c;
}
