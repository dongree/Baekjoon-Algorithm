// const fs = require('fs');

// const inputs = fs.readFileSync('example.txt').toString().split('\n');

// const T = +inputs[0];
// const n = +inputs[1];
// const A = inputs[2].split(' ').map(Number);
// const m = +inputs[3];
// const B = inputs[4].split(' ').map(Number);

// const AA = [];
// const BB = [];

// for (let i = 0; i < A.length; i++) {
//   let sum = A[i];
//   AA.push(sum);
//   for (let j = i + 1; j < A.length; j++) {
//     sum += A[j];
//     AA.push(sum);
//   }
// }

// for (let i = 0; i < B.length; i++) {
//   let sum = B[i];
//   BB.push(sum);
//   for (let j = i + 1; j < B.length; j++) {
//     sum += B[j];
//     BB.push(sum);
//   }
// }

// console.log(AA);
// console.log(BB);

const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().split('\n');
const T = +inputs[0];
const a = inputs[2].split(' ').map(Number);
const b = inputs[4].split(' ').map(Number);

let answer = 0;

let aMap = new Map();
for (let i = 0; i < a.length; i++) {
  let sum = 0;
  for (let j = i; j < a.length; j++) {
    sum += a[j];
    aMap.set(sum, (aMap.get(sum) ?? 0) + 1);
  }
}

for (let i = 0; i < b.length; i++) {
  let sum = 0;
  for (let j = i; j < b.length; j++) {
    sum += b[j];
    answer += aMap.get(T - sum) ?? 0;
  }
}

console.log(answer);
