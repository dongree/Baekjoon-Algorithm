const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString().trim();

let arr = [];
for (let i = 1; i <= N; i++) {
  arr.push(i);
}

while (arr.length !== 1) {
  const newArr = [];
  for (let i = 1; i < arr.length; i += 2) {
    newArr.push(arr[i]);
  }
  arr = newArr;
}

console.log(arr[0]);
