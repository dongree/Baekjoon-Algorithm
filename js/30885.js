const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
let arr = inputs[1].split(' ').map((e, i) => [+e, i + 1]);

while (arr.length !== 1) {
  const dp = Array(arr.length).fill(0);

  for (let i = 0; i < arr.length; i++) {
    if (i > 0) dp[i] = dp[i - 1];

    if (arr[i][0] === 0) continue;

    let temp = arr[i][0];
    if (i - 1 >= 0 && arr[dp[i]][0] <= arr[i][0]) {
      temp += arr[dp[i]][0];
      arr[dp[i]][0] = 0;
    }
    if (i + 1 < arr.length && arr[i + 1][0] <= arr[i][0]) {
      temp += arr[i + 1][0];
      arr[i + 1][0] = 0;
    }
    arr[i][0] = temp;
    dp[i] = i;
  }

  arr = arr.filter((e) => e[0] !== 0);
}

console.log(arr[0].join('\n'));
