// 내 풀이
const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const N = +inputs[0];
const arr = [];

for (let i = 1; i <= N; i++) {
  const subArr = inputs[i].split(' ').map(Number);
  arr.push(subArr);
}

arr.sort((a, b) => a[0] - b[0]);

let result = 0;
let idx = 0;

let flag = true;
while (flag) {
  flag = false;
  const start = arr[idx][0];
  let end = arr[idx][1];
  for (let i = idx + 1; i < N; i++) {
    if (arr[i][0] <= end && arr[i][1] > end) {
      end = arr[i][1];
    } else if (arr[i][0] > end) {
      flag = true;
      idx = i;
      break;
    }
  }
  result += end - start;
}

console.log(result);

// 다른 사람 풀이
// const fs = require('fs');

// const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

// const N = +inputs[0];
// const arr = [];

// for (let i = 1; i <= N; i++) {
//   const subArr = inputs[i].split(' ').map(Number);
//   arr.push(subArr);
// }

// arr.sort((a, b) => a[0] - b[0]);

// let result = 0;

// let start = arr[0][0];
// let end = arr[0][1];

// for (let i = 1; i < N; i++) {
//   if (arr[i][0] <= end && arr[i][1] > end) {
//     end = arr[i][1];
//   } else if (arr[i][0] > end) {
//     result += end - start;
//     start = arr[i][0];
//     end = arr[i][1];
//   }
// }
// result += end - start;

// console.log(result);
