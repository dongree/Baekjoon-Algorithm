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

const sudoku = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e, i) =>
    e.split(' ').map((num, j) => {
      num = +num;
      row[i][num] = true;
      col[j][num] = true;
      box[Math.floor(i / 3) * 3 + Math.floor(j / 3)][num] = true;
      return num;
    })
  );

let end = false;

dfs(0);

function dfs(cnt) {
  const y = Math.floor(cnt / 9);
  const x = cnt % 9;

  if (end) return;

  if (cnt === 81) {
    console.log(sudoku.map((e) => e.join(' ')).join('\n'));
    end = true;
    return;
  }

  if (sudoku[y][x] === 0) {
    for (let k = 1; k <= 9; k++) {
      const boxLoc = Math.floor(y / 3) * 3 + Math.floor(x / 3);
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
