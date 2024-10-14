const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const pictures = [];
let N = +getLine();

for (let t = 0; t < N; t++) {
  const arr = [];
  for (let i = 0; i < 5; i++) {
    arr.push(getLine());
  }
  pictures.push(arr);
}

let minCnt = Infinity;
let result = '';

for (let i = 0; i < N; i++) {
  for (let j = i + 1; j < N; j++) {
    let cnt = 0;
    for (let y = 0; y < 5; y++) {
      for (let x = 0; x < 7; x++) {
        if (pictures[i][y][x] !== pictures[j][y][x]) cnt++;
      }
    }
    if (cnt < minCnt) {
      minCnt = cnt;
      result = `${i + 1} ${j + 1}`;
    }
  }
}

console.log(result);
