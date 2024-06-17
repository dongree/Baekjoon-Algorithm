const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const target = +getLine();
const [m, n] = getLine().split(' ').map(Number);

const pizza1 = [];
const pizza2 = [];

for (let i = 0; i < m; i++) {
  pizza1.push(+getLine());
}

for (let j = 0; j < n; j++) {
  pizza2.push(+getLine());
}

const sum1 = [0];
const sum2 = [0];

for (let i = 0; i < m; i++) {
  let k = 0;
  for (let j = i; j < i + m - 1; j++) {
    k += pizza1[j % m];
    sum1.push(k);
  }
}
sum1.push(pizza1.reduce((a, b) => a + b));

for (let i = 0; i < n; i++) {
  let k = 0;
  for (let j = i; j < i + n - 1; j++) {
    k += pizza2[j % n];
    sum2.push(k);
  }
}
sum2.push(pizza2.reduce((a, b) => a + b));

sum1.sort((a, b) => a - b);
sum2.sort((a, b) => a - b);

let ans = 0;

for (let i = 0; i < sum1.length; i++) {
  const value = target - sum1[i];

  if (value < 0) break;

  const low = lowerBound(value, sum2);
  const high = upperBound(value, sum2);

  ans += high - low;
}

console.log(ans);

function lowerBound(target, arr) {
  let start = 0;
  let end = arr.length;

  while (start < end) {
    const mid = Math.floor((start + end) / 2);
    if (arr[mid] >= target) end = mid;
    else start = mid + 1;
  }
  return end;
}

function upperBound(target, arr) {
  let start = 0;
  let end = arr.length;

  while (start < end) {
    const mid = Math.floor((start + end) / 2);
    if (arr[mid] > target) end = mid;
    else start = mid + 1;
  }
  return end;
}
