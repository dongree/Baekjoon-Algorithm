// #1 풀이
// const fs = require('fs');

// const [s1, s2] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

// const len1 = s1.length;
// const len2 = s2.length;

// // dp[i][j] : i의 길이를 가진 문자열 s1과 j의 길이를 가진 문자열 s2의 LCS
// const dp = Array(len1 + 1)
//   .fill()
//   .map(() => Array(len2 + 1).fill(''));

// for (let i = 1; i <= len1; i++) {
//   for (let j = 1; j <= len2; j++) {
//     if (s1[i - 1] === s2[j - 1]) {
//       dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
//     } else {
//       dp[i][j] =
//         dp[i - 1][j].length > dp[i][j - 1].length ? dp[i - 1][j] : dp[i][j - 1];
//     }
//   }
// }

// console.log(dp[len1][len2].length);
// console.log(dp[len1][len2]);

// #2풀이
const fs = require('fs');

const [s1, s2] = fs.readFileSync('example.txt').toString().trim().split('\n');

const len1 = s1.length;
const len2 = s2.length;

// dp[i][j] : i의 길이를 가진 문자열 s1과 j의 길이를 가진 문자열 s2의 LCS
const dp = Array(len1 + 1)
  .fill()
  .map(() => Array(len2 + 1).fill(0));

for (let i = 1; i <= len1; i++) {
  for (let j = 1; j <= len2; j++) {
    if (s1[i - 1] === s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
    else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
  }
}

let i = len1;
let j = len2;
let answer = '';

while (i && j) {
  if (dp[i][j] === dp[i - 1][j]) i--;
  else if (dp[i][j] === dp[i][j - 1]) j--;
  else {
    answer = s1[i - 1] + answer;
    i--;
    j--;
  }
}

console.log(answer.length);
console.log(answer);
