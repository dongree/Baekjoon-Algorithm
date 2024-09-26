const fs = require('fs');

const [s1, s2, s3] = fs.readFileSync('example.txt').toString().trim().split(' ').map(Number);

const sum = Array(s1 + s2 + s3 + 1).fill(0);

for (let i = 1; i <= s1; i++) {
  for (let j = 1; j <= s2; j++) {
    for (let k = 1; k <= s3; k++) {
      sum[i + j + k]++;
    }
  }
}

const result = sum.findIndex((e) => e === Math.max(...sum));

console.log(result);
