const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const M = +inputs[1];

const arr = inputs[2].split(' ').map(Number);

const frames = [];

for (let i = 0; i < M; i++) {
  let alreadyOn = false;
  let targetI = -1;
  let targetCnt = Infinity;
  let targetOrder = Infinity;
  for (let j = 0; j < frames.length; j++) {
    const { num, cnt, order } = frames[j];

    if (num === arr[i]) {
      alreadyOn = true;
      frames[j].cnt++;
      break;
    }
    if (targetCnt > cnt || (targetCnt === cnt && targetOrder > order)) {
      targetI = j;
      targetCnt = cnt;
      targetOrder = order;
    }
  }

  if (!alreadyOn) {
    if (frames.length !== N) {
      frames.push({
        num: arr[i],
        cnt: 1,
        order: i,
      });
    } else {
      frames[targetI] = {
        num: arr[i],
        cnt: 1,
        order: i,
      };
    }
  }
}

const result = frames
  .map((e) => e.num)
  .sort((a, b) => a - b)
  .join(' ');

console.log(result);
