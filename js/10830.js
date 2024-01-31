const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let [N, B] = inputs[0].split(' ').map(Number);
B = BigInt(B);
const MOD = 1000n;

const matrix = [];

for (let i = 1; i <= N; i++) {
  const subArr = inputs[i].split(' ').map((e) => BigInt(e) % MOD);
  matrix.push(subArr);
}

const result = power(matrix, B)
  .map((subArr) => subArr.join(' '))
  .join('\n');

console.log(result);

function power(matrix, n) {
  if (n === 1n) return matrix;

  const temp = power(matrix, n / 2n);
  if (n % 2n === 0n) return mult(temp, temp);
  else return mult(mult(temp, temp), matrix);
}

function mult(mat1, mat2) {
  const res = Array(N)
    .fill()
    .map(() => Array(N).fill(0n));

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      for (let k = 0; k < N; k++) {
        res[i][j] = (res[i][j] + mat1[i][k] * mat2[k][j]) % MOD;
      }
    }
  }

  return res;
}
