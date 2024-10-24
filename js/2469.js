const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const k = +getLine();
const n = +getLine();
const target = getLine();

const alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';

const sadsri = [];
let row = 0;

for (let i = 0; i < n; i++) {
  const arr = getLine().split('');
  if (arr[0] === '?') row = i + 1;
  sadsri.push(arr);
}

const hist = Array(n + 1)
  .fill()
  .map(() => Array(k).fill(''));

for (let i = 0; i < k; i++) {
  hist[0][i] = alphabet[i];
  hist[n][i] = target[i];
}

for (let i = 1; i < row; i++) {
  for (let j = 0; j < k; j++) {
    if (j - 1 >= 0 && sadsri[i - 1][j - 1] === '-') {
      hist[i][j - 1] = hist[i - 1][j];
    } else if (j < k - 1 && sadsri[i - 1][j] === '-') {
      hist[i][j + 1] = hist[i - 1][j];
    } else {
      hist[i][j] = hist[i - 1][j];
    }
  }
}

for (let i = n - 1; i >= row; i--) {
  for (let j = 0; j < k; j++) {
    if (j - 1 >= 0 && sadsri[i][j - 1] === '-') {
      hist[i][j - 1] = hist[i + 1][j];
    } else if (j < k - 1 && sadsri[i][j] === '-') {
      hist[i][j + 1] = hist[i + 1][j];
    } else {
      hist[i][j] = hist[i + 1][j];
    }
  }
}

const start = [...hist[row - 1]];
const finish = [...hist[row]];

let result = '';

for (let i = 0; i < k - 1; i++) {
  if (start[i] === finish[i]) {
    result += '*';
  } else if (start[i] === finish[i + 1] && start[i + 1] === finish[i]) {
    [start[i], start[i + 1]] = [start[i + 1], start[i]];
    result += '-';
  } else {
    result = 'x'.repeat(k - 1);
    break;
  }
}

console.log(result);
