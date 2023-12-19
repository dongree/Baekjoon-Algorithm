const fs = require('fs');

const inputs = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

// recursion 풀이
inputs.forEach((n) => {
  const arr = Array(Math.pow(3, n))
    .fill()
    .map(() => '-');
  makeCantor(0, arr.length);
  console.log(arr.join(''));

  function makeCantor(start, num) {
    if (num === 1) return;
    const gap = num / 3;
    const first = start;
    const second = start + gap;
    const third = start + gap * 2;
    for (let i = second; i < third; i++) {
      arr[i] = ' ';
    }
    makeCantor(start, gap);
    makeCantor(third, gap);
  }
});

// DP 풀이
// const dp = Array(13)
//   .fill()
//   .map(() => '');

// dp[0] = '-';

// for (let i = 1; i < 13; i++) {
//   dp[i] = dp[i - 1] + ' '.repeat(Math.pow(3, i - 1)) + dp[i - 1];
// }

// inputs.forEach((n) => {
//   console.log(dp[n]);
// });
