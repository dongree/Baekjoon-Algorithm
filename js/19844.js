const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

const e = ['c', 'j', 'n', 'm', 't', 's', 'l', 'd', 'qu'];
const vowels = ['a', 'e', 'i', 'o', 'u', 'h'];

const arr = s.replaceAll(' ', '-').split('-');

let result = arr.length;

for (let i = 0; i < arr.length; i++) {
  if (!arr[i].includes("'")) continue;

  const [a, b] = arr[i].split("'");

  if (e.includes(a) && vowels.includes(b[0])) result++;
}

console.log(result);
