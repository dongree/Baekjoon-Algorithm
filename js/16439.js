const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);

const arr = [];

for (let i = 1; i <= N; i++) {
  arr.push(inputs[i].split(' ').map(Number));
}

let result = 0;

for (let i = 0; i < M; i++) {
  for (let j = i + 0; j < M; j++) {
    for (let k = j + 0; k < M; k++) {
      let sum = 0;
      for (let p = 0; p < N; p++) {
        sum += Math.max(arr[p][i], arr[p][j], arr[p][k]);
      }
      result = Math.max(sum, result);
    }
  }
}

console.log(result);
