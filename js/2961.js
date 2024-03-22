// 내 풀이

// const fs = require('fs');

// const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

// const N = +inputs[0];
// const arr = [];

// for (let i = 1; i <= N; i++) {
//   arr.push(inputs[i].split(' ').map(Number));
// }

// let answer = Infinity;

// dfs(0, 1, 0);

// console.log(answer);

// function dfs(idx, s, b) {
//   if (s !== 0 && b !== 0) {
//     answer = Math.min(answer, Math.abs(s - b));
//   }

//   for (let i = idx; i < N; i++) {
//     dfs(i + 1, s * arr[i][0], b + arr[i][1]);
//   }
// }

// bit mask 풀이
const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = [];

for (let i = 1; i <= N; i++) {
  arr.push(inputs[i].split(' ').map(Number));
}

let answer = Infinity;

for (let i = 1; i < 1 << N; i++) {
  let s = 1;
  let b = 0;
  for (let j = 0; j < N; j++) {
    if (i & (1 << j)) {
      s *= arr[j][0];
      b += arr[j][1];
    }
  }
  answer = Math.min(answer, Math.abs(s - b));
}

console.log(answer);
