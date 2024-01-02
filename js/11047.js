const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let [n, k] = inputs[0].split(' ').map(Number);
const coinType = [];
let answer = 0;
let idx = n - 1;

for (let i = 1; i <= n; i++) {
  coinType.push(+inputs[i]);
}

while (k !== 0) {
  if (k >= coinType[idx]) {
    const num = Math.floor(k / coinType[idx]);
    k -= num * coinType[idx];
    answer += num;
  }
  idx--;
}

console.log(answer);
