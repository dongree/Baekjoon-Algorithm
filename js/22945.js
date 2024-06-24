const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const arr = inputs[1].split(' ').map(Number);

let i = 0;
let j = arr.length - 1;

let ans = 0;

while (i < j) {
  const k = Math.min(arr[i], arr[j]) * (j - i - 1);

  ans = Math.max(ans, k);

  if (arr[i] < arr[j]) i++;
  else j--;
}

console.log(ans);
