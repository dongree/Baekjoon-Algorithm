const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, L] = inputs[0].split(' ').map(Number);
const map = [];
const isVisited = Array(N).fill(false);
let answer = 0;

for (let i = 1; i <= N; i++) {
  const subArr = inputs[i].split(' ').map(Number);
  map.push(subArr);
}

for (let i = 0; i < N; i++) {
  if (checkRoad(i, 0)) answer++;
  if (checkRoad(i, 1)) answer++;
}

console.log(answer);

function checkRoad(n, dir) {
  initIsVisited();
  let prev = dir ? map[0][n] : map[n][0];
  for (let i = 1; i < N; i++) {
    const curr = dir ? map[i][n] : map[n][i];
    if (prev === curr) {
      prev = curr;
      continue;
    } else {
      if (Math.abs(curr - prev) > 1) return false;
      if (prev < curr) {
        if (i - L < 0) return false;
        for (let j = i - L; j < i; j++) {
          if ((dir ? map[j][n] : map[n][j]) !== prev || isVisited[j])
            return false;
          else isVisited[j] = true;
        }
      } else {
        if (i + L > N) return false;
        for (let j = i; j < i + L; j++) {
          if ((dir ? map[j][n] : map[n][j]) !== curr || isVisited[j])
            return false;
          else isVisited[j] = true;
        }
      }
    }
    prev = curr;
  }
  return true;
}

function initIsVisited() {
  for (let i = 0; i < N; i++) {
    isVisited[i] = false;
  }
}
