const fs = require('fs');

let [[N], ...arr] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

while (N !== 1) {
  const newArr = [];

  for (let i = 0; i < N; i += 2) {
    const row = [];
    for (let j = 0; j < N; j += 2) {
      const tempArr = [];
      for (let a = i; a < i + 2; a++) {
        for (let b = j; b < j + 2; b++) {
          tempArr.push(arr[a][b]);
        }
      }
      tempArr.sort((a, b) => b - a);
      row.push(tempArr[1]);
    }
    newArr.push(row);
  }
  N /= 2;

  arr = newArr;
}

console.log(arr[0][0]);
