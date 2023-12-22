const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, m] = inputs[0].split(' ').map(Number);
const arr = inputs[1].split(' ').map(Number);
const acc_num = [0];
const cnt = Array(m).fill(0);

let result = 0;

for (let i = 0; i < n; i++) {
  const num = (acc_num[i] + arr[i]) % m;
  acc_num.push(num);
  cnt[num]++;
  if (num === 0) result++;
}

cnt.forEach((c) => {
  result += (c * (c - 1)) / 2;
});

console.log(result);
