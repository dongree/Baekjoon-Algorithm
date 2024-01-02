const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = inputs[0];
const times = [];

for (let i = 1; i <= n; i++) {
  times.push(inputs[i].split(' ').map(Number));
}

times.sort((a, b) => {
  if (a[1] === b[1]) {
    return a[0] - b[0];
  } else {
    return a[1] - b[1];
  }
});

let answer = 0;
let k = 0;

times.forEach((time) => {
  if (time[0] >= k) {
    k = time[1];
    answer++;
  }
});

console.log(answer);
