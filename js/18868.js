const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

const [M, N] = inputs[0];

const spaces = [];
for (let i = 1; i <= M; i++) {
  spaces.push(inputs[i]);
}

let cnt = 0;
for (let i = 0; i < M; i++) {
  for (let j = i + 1; j < M; j++) {
    let flag = true;
    a: for (let k = 0; k < N; k++) {
      for (let l = k + 1; l < N; l++) {
        if (spaces[i][k] < spaces[i][l] && spaces[j][k] < spaces[j][l]) continue;
        if (spaces[i][k] === spaces[i][l] && spaces[j][k] === spaces[j][l]) continue;
        if (spaces[i][k] > spaces[i][l] && spaces[j][k] > spaces[j][l]) continue;
        flag = false;
        break a;
      }
    }
    if (flag) cnt++;
  }
}

console.log(cnt);
