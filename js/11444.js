const fs = require('fs');

let n = BigInt(fs.readFileSync('example.txt').toString().trim());

let matrix = [
  [1n, 1n],
  [1n, 0n],
];

console.log((power(n)[1][0] % 1000000007n).toString());

function power(n) {
  if (n === 1n) return matrix;
  else {
    const temp = power(n / 2n);
    if (n % 2n === 0n) return multiplyMatrix(temp, temp);
    else return multiplyMatrix(multiplyMatrix(temp, temp), matrix);
  }
}

function multiplyMatrix(a, b) {
  const res = [
    [0n, 0n],
    [0n, 0n],
  ];
  for (let i = 0; i < 2; i++) {
    for (let j = 0; j < 2; j++) {
      for (let k = 0; k < 2; k++) {
        res[i][j] += (a[i][k] * b[k][j]) % 1000000007n;
      }
    }
  }
  return res;
}
