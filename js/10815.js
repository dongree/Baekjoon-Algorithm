const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const myArr = inputs[1].split(' ').map(Number);
const comparisonArr = inputs[3].split(' ').map(Number);

const map = new Map();

myArr.forEach((e) => {
  map.set(e, 1);
});

const result = comparisonArr
  .map((e) => (map.get(e) === undefined ? 0 : 1))
  .join(' ');

console.log(result);
