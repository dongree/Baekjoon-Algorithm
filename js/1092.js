// my solution

// const fs = require('fs');

// const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

// const N = +inputs[0];
// const crains = inputs[1]
//   .split(' ')
//   .map(Number)
//   .sort((a, b) => b - a);
// let M = +inputs[2];
// const boxes = inputs[3]
//   .split(' ')
//   .map(Number)
//   .sort((a, b) => b - a);

// const isVisited = Array(M).fill(false);

// if (boxes[0] > crains[0]) {
//   console.log(-1);
// } else {
//   let t = 0;
//   while (0 < M) {
//     for (let i = 0; i < crains.length; i++) {
//       for (let j = 0; j < boxes.length; j++) {
//         if (isVisited[j]) continue;
//         if (crains[i] >= boxes[j]) {
//           isVisited[j] = true;
//           M--;
//           break;
//         }
//       }
//     }

//     t++;
//   }

//   console.log(t);
// }

const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const crains = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => b - a);
let M = +inputs[2];
const boxes = inputs[3]
  .split(' ')
  .map(Number)
  .sort((a, b) => b - a);

if (boxes[0] > crains[0]) {
  console.log(-1);
} else {
  let t = 0;
  while (boxes.length) {
    cIdx = 0;
    bIdx = 0;
    while (cIdx < crains.length && bIdx < boxes.length) {
      if (crains[cIdx] >= boxes[bIdx]) {
        cIdx++;
        boxes.splice(bIdx, 1);
      } else {
        bIdx++;
      }
    }

    t++;
  }

  console.log(t);
}
