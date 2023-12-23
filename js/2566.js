const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim('').split('\n');

const arr = inputs.map((e) => e.split(' ').map(Number));

let maxResult = -Infinity;
let y, x;

arr.forEach((subArr, i) => {
  subArr.forEach((num, j) => {
    if (num > maxResult) {
      maxResult = num;
      y = i;
      x = j;
    }
  });
});

console.log(maxResult);
console.log(y + 1, x + 1);
