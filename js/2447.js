const fs = require('fs');

const n = +fs.readFileSync('/dev/stdin').toString();

// recursion
const arr = Array(n)
  .fill()
  .map(() => Array(n).fill('*'));

recursion(0, 0, n);
arr.forEach((subArr) => console.log(subArr.join('')));

function recursion(y, x, n) {
  if (n === 1) return;
  const gap = n / 3;

  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      const startY = y + i * gap;
      const startX = x + j * gap;
      if (i === 1 && j === 1) {
        for (let m = startY; m < startY + gap; m++) {
          for (let n = startX; n < startX + gap; n++) {
            arr[m][n] = ' ';
          }
        }
        continue;
      }
      recursion(startY, startX, gap);
    }
  }
}

// dp
// 참고 : https://www.acmicpc.net/source/70482333
// const dp = ['*'];

// const getOddFloor = (from) => {
//   const tmp = from.split('\n');
//   let result = '';
//   tmp.forEach((str) => (result += str.repeat(3) + '\n'));
//   return result;
// };
// const getEvenFloor = (from) => {
//   const tmp = from.split('\n');
//   let result = '';
//   tmp.forEach((str) => (result += str + ' '.repeat(str.length) + str + '\n'));
//   return result;
// };

// for (let i = n; i > 1; i /= 3) {
//   const lastStr = dp[dp.length - 1];
//   const layerStr = getOddFloor(lastStr);
//   dp.push((layerStr + getEvenFloor(lastStr) + layerStr).trim());
// }

// console.log(dp.pop());
