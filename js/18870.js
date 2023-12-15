const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];
const arr = inputs[1].split(' ').map(Number);

const sortedArr = [...arr].sort((a, b) => a - b);

let i = 0;
const map = new Map();

sortedArr.forEach((item) => {
  if (map.get(item) === undefined) {
    map.set(item, i);
    i++;
  }
});

const result = arr.map((item) => map.get(item)).join(' ');

console.log(result);
