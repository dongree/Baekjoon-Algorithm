// 내 풀이

const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1].split(' ').map(Number);

const dp = Array(N)
  .fill()
  .map(() => Array(2).fill(0));

for (let i = 0; i < N; i++) {
  let k = 0;
  let tempJ = -1;
  for (let j = 0; j < i; j++) {
    if (arr[j] < arr[i] && k < dp[j][0]) {
      k = dp[j][0];
      tempJ = j;
    }
  }
  dp[i][0] = k + 1;
  dp[i][1] = tempJ;
}

let maxI = 0;
let maxL = 0;
for (let i = 0; i < N; i++) {
  if (maxL < dp[i][0]) {
    maxL = dp[i][0];
    maxI = i;
  }
}

const answer = [];
let i = maxI;

while (i !== -1) {
  answer.push(arr[i]);
  i = dp[i][1];
}

console.log(maxL);
console.log(answer.reverse().join(' '));
