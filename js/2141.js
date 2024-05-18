const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];

const arr = [];

for (let i = 1; i <= N; i++) {
  arr.push(inputs[i].split(' ').map(Number));
}

arr.sort((a, b) => a[0] - b[0]);

const peopleNum = arr.reduce((a, b) => a + b[1], 0);

let sum = 0;
let flag = false;

for (let i = 0; i < N; i++) {
  sum += arr[i][1];
  if (sum >= peopleNum / 2) {
    console.log(arr[i][0]);
    flag = true;
    break;
  }
}

if (!flag) {
  console.log(arr[N - 1][0]);
}
