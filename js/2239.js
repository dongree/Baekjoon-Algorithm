// #1
// const fs = require('fs');

// const row = Array(9)
//   .fill()
//   .map(() => Array(10).fill(false));
// const col = Array(9)
//   .fill()
//   .map(() => Array(10).fill(false));
// const box = Array(9)
//   .fill()
//   .map(() => Array(10).fill(false));

// let emptyNums = 0;
// let end = false;

// const sudoku = fs
//   .readFileSync('/dev/stdin')
//   .toString()
//   .trim()
//   .split('\n')
//   .map((e, i) =>
//     e.split('').map((v, j) => {
//       if (+v === 0) emptyNums++;
//       row[i][+v] = true;
//       col[j][+v] = true;
//       box[3 * Math.floor(i / 3) + Math.floor(j / 3)][+v] = true;
//       return +v;
//     })
//   );

// dfs(0);

// function dfs(cnt) {
//   if (end) return;

//   if (cnt === emptyNums) {
//     console.log(sudoku.map((e) => e.join('')).join('\n'));
//     end = true;
//     return;
//   }

//   for (let i = 0; i < 9; i++) {
//     for (let j = 0; j < 9; j++) {
//       if (sudoku[i][j] === 0) {
//         for (let k = 1; k <= 9; k++) {
//           const boxLoc = 3 * Math.floor(i / 3) + Math.floor(j / 3);
//           if (!row[i][k] && !col[j][k] && !box[boxLoc][k]) {
//             sudoku[i][j] = k;
//             row[i][k] = true;
//             col[j][k] = true;
//             box[boxLoc][k] = true;
//             dfs(cnt + 1);
//             sudoku[i][j] = 0;
//             row[i][k] = false;
//             col[j][k] = false;
//             box[boxLoc][k] = false;
//           }
//           if (k === 9) return;
//         }
//       }
//     }
//   }
// }

// #2 better solution
const fs = require('fs');

const row = Array(9)
  .fill()
  .map(() => Array(10).fill(false));
const col = Array(9)
  .fill()
  .map(() => Array(10).fill(false));
const box = Array(9)
  .fill()
  .map(() => Array(10).fill(false));

let end = false;
const sudoku = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e, i) =>
    e.split('').map((v, j) => {
      row[i][+v] = true;
      col[j][+v] = true;
      box[3 * Math.floor(i / 3) + Math.floor(j / 3)][+v] = true;
      return +v;
    })
  );

dfs(0);

function dfs(cnt) {
  const y = Math.floor(cnt / 9);
  const x = cnt % 9;

  if (end) return;

  if (cnt === 81) {
    console.log(sudoku.map((e) => e.join('')).join('\n'));
    end = true;
    return;
  }

  if (sudoku[y][x] === 0) {
    for (let k = 1; k <= 9; k++) {
      const boxLoc = 3 * Math.floor(y / 3) + Math.floor(x / 3);
      if (!row[y][k] && !col[x][k] && !box[boxLoc][k]) {
        sudoku[y][x] = k;
        row[y][k] = true;
        col[x][k] = true;
        box[boxLoc][k] = true;
        dfs(cnt + 1);
        sudoku[y][x] = 0;
        row[y][k] = false;
        col[x][k] = false;
        box[boxLoc][k] = false;
      }
    }
  } else {
    dfs(cnt + 1);
  }
}
