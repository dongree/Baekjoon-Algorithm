const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

const arr = Array(5).fill(0);

let isWrong = false;
let minCnt = 0;

for (let i = 0; i < s.length; i++) {
  if (s[i] === 'q') {
    arr[0]++;
    if (minCnt > 0) minCnt -= 1;
  } else if (s[i] === 'u') {
    if (arr[0] > arr[1]) arr[1]++;
    else {
      isWrong = true;
      break;
    }
  } else if (s[i] === 'a') {
    if (arr[1] > arr[2]) arr[2]++;
    else {
      isWrong = true;
      break;
    }
  } else if (s[i] === 'c') {
    if (arr[2] > arr[3]) arr[3]++;
    else {
      isWrong = true;
      break;
    }
  } else if (s[i] === 'k') {
    if (arr[3] > arr[4]) {
      arr[4]++;
      minCnt++;
    } else {
      isWrong = true;
      break;
    }
  }
}

let a = arr[0];
for (let i = 1; i < 5; i++) {
  if (a !== arr[i]) isWrong = true;
}

if (isWrong) {
  console.log(-1);
} else {
  console.log(minCnt);
}
