// const fs = require('fs');

// const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

// const N = +inputs[0];
// const board = [];
// const isVisited = Array(N)
//   .fill()
//   .map(() => Array(N).fill(false));
// const dy = [1, 1, -1, -1];
// const dx = [1, -1, 1, -1];
// let answer = 0;

// for (let i = 1; i <= N; i++) {
//   board.push(inputs[i].split(' ').map(Number));
// }

// let result = 0;

// dfs(0, 0, 1);
// result += answer;
// answer = 0;
// dfs(0, 0, 0);
// result += answer;
// console.log(result);

// function dfs(cur, cnt, color) {
//   answer = Math.max(answer, cnt);

//   for (let i = cur; i < N * N; i++) {
//     let y = Math.floor(i / N);
//     let x = i % N;

//     if (color && (x + y) % 2 !== 0) continue;
//     if (!color && (x + y) % 2 === 0) continue;

//     if (board[y][x] && !isVisited[y][x] && isOk(y, x)) {
//       isVisited[y][x] = true;
//       dfs(i + 1, cnt + 1, color);
//       isVisited[y][x] = false;
//     }
//   }
// }

// function isOk(y, x) {
//   for (let i = 0; i < 4; i++) {
//     let ny = y + dy[i];
//     let nx = x + dx[i];
//     while (0 <= ny && ny < N && 0 <= nx && nx < N) {
//       if (isVisited[ny][nx]) return false;
//       ny += dy[i];
//       nx += dx[i];
//     }
//   }
//   return true;
// }

const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const board = [];
const isVisited1 = Array(N * 2).fill(false);
const isVisited2 = Array(N * 2).fill(false);
let answer = 0;

for (let i = 1; i <= N; i++) {
  board.push(inputs[i].split(' ').map(Number));
}

let result = 0;

dfs(0, 0, 1);
result += answer;
answer = 0;
dfs(0, 0, 0);
result += answer;
console.log(result);

function dfs(cur, cnt, color) {
  answer = Math.max(answer, cnt);

  for (let i = cur; i < N * N; i++) {
    let y = Math.floor(i / N);
    let x = i % N;

    if (color && (x + y) % 2 !== 0) continue;
    if (!color && (x + y) % 2 === 0) continue;

    if (board[y][x] && !isVisited1[y + x] && !isVisited2[y - x + N]) {
      isVisited1[y + x] = true;
      isVisited2[y - x + N] = true;
      dfs(i + 1, cnt + 1, color);
      isVisited1[y + x] = false;
      isVisited2[y - x + N] = false;
    }
  }
}
