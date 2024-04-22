const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const arr = [];
const arr2 = [];
let ans = 0;

for (let i = 1; i <= N; i++) {
  const value = +inputs[i];
  if (value > 0) arr.push(value);
  else arr2.push(value);
}

arr.sort((a, b) => b - a);
arr2.sort((a, b) => a - b);

for (let i = 0; i < arr.length; i++) {
  if (i === arr.length - 1) {
    ans += arr[i];
  } else {
    const a = arr[i];
    const b = arr[i + 1];

    if (a * b > a + b) {
      ans += a * b;
      i++;
    } else {
      ans += a;
    }
  }
}

for (let i = 0; i < arr2.length; i++) {
  if (i === arr2.length - 1) {
    ans += arr2[i];
  } else {
    const a = arr2[i];
    const b = arr2[i + 1];

    if (a * b > a + b) {
      ans += a * b;
      i++;
    } else {
      ans += a;
    }
  }
}

console.log(ans);
