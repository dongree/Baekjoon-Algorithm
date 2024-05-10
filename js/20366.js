const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = inputs[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);

let min = Infinity;

search: for (let i = 0; i < N; i++) {
  for (let j = i + 1; j < N; j++) {
    const snowMan1 = arr[i] + arr[j];
    let start = 0;
    let end = N - 1;
    while (start < end) {
      if (start === i || start === j) {
        start++;
        continue;
      }
      if (end === i || end === j) {
        end--;
        continue;
      }

      const snowMan2 = arr[start] + arr[end];
      min = Math.min(min, Math.abs(snowMan1 - snowMan2));

      if (snowMan1 > snowMan2) start++;
      else if (snowMan1 < snowMan2) end--;
      else {
        min = 0;
        break search;
      }
    }
  }
}

console.log(min);
