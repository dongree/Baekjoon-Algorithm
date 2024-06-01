// my solution
// const fs = require('fs');

// const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

// const N = +inputs[0];
// const s = inputs[1];
// let newS = '';

// console.log(s.split('B'));

// let bCnt = 0;
// let rCnt = 0;

// let preS = '';

// for (let i = 0; i < N; i++) {
//   if (preS !== s[i]) {
//     if (s[i] === 'B') newS += 'B';
//     else newS += 'R';
//   }
//   preS = s[i];
// }

// for (let i = 0; i < newS.length; i++) {
//   if (newS[i] === 'B') bCnt++;
//   else rCnt++;
// }

// console.log(Math.min(bCnt, rCnt) + 1);

const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const s = inputs[1];

let bCnt = s.split('R').filter((i) => i).length;
let rCnt = s.split('B').filter((i) => i).length;

console.log(Math.min(bCnt, rCnt) + 1);
