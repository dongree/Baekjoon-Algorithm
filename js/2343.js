const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);
const lecturesM = inputs[1].split(' ').map(Number);

let start = Math.max(...lecturesM);
let end = lecturesM.reduce((a, b) => a + b, 0);

while (start <= end) {
  const mid = Math.floor((start + end) / 2);

  let bluelayCnt = 1;
  let mCnt = 0;
  lecturesM.forEach((m) => {
    if (mCnt + m > mid) {
      mCnt = 0;
      bluelayCnt++;
    }
    mCnt += m;
  });

  if (bluelayCnt <= M) end = mid - 1;
  else start = mid + 1;
}

console.log(start);
