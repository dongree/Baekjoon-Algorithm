const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, x] = inputs[0].split(' ').map(Number);
const arr = inputs[1].split(' ').map(Number);

let visitedNum = 0;
for (let i = 0; i < x; i++) {
  visitedNum += arr[i];
}
let maxVisitedNum = visitedNum;
let cnt = 1;

for (let i = 0; i < n - x; i++) {
  visitedNum -= arr[i];
  visitedNum += arr[i + x];
  if (maxVisitedNum < visitedNum) {
    maxVisitedNum = visitedNum;
    cnt = 1;
  } else if (maxVisitedNum === visitedNum) cnt++;
}

if (maxVisitedNum === 0) console.log('SAD');
else {
  console.log(`${maxVisitedNum}\n${cnt}`);
}
