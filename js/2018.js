const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString().trim();

let start = 1;
let end = 1;
let value = 1;
let cnt = 0;

while (end <= N && start <= end) {
  console.log(start, end, value);
  if (value <= N) {
    if (value === N) {
      cnt++;
    }
    value += ++end;
  } else {
    value -= start++;
  }
}

console.log(cnt);
