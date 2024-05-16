const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim('')
  .split('\n')
  .map(Number);

let idx = 0;
const getLine = () => inputs[idx++];

const G = getLine();
let P = getLine();

const parents = Array(G + 1)
  .fill()
  .map((_, e) => e);
let ans = 0;

for (let n = 1; n <= P; n++) {
  10;
  const g = getParent(getLine());

  if (g != 0) {
    unionParent(g, g - 1);
    ans++;
  } else break;
}

console.log(ans);

function getParent(x) {
  if (x === parents[x]) return x;
  else return (parents[x] = getParent(parents[x]));
}

function unionParent(a, b) {
  a = getParent(a);
  b = getParent(b);

  if (a > b) parents[a] = b;
  else if (a < b) parents[b] = a;
}

// my solution1
// const fs = require('fs');

// const inputs = fs
//   .readFileSync('/dev/stdin')
//   .toString()
//   .trim('')
//   .split('\n')
//   .map(Number);

// let idx = 0;
// const getLine = () => inputs[idx++];

// const G = getLine();
// let P = getLine();

// const isVisited = Array(G + 1).fill(false);
// const parents = Array(G + 1)
//   .fill()
//   .map((_, e) => e);
// let ans = 0;

// for (let n = 1; n <= P; n++) {
//   const g = getParent(getLine());
//   let flag = false;

//   for (let i = g; i >= 1; i--) {
//     if (!isVisited[i]) {
//       isVisited[i] = true;
//       unionParent(g, i);
//       flag = true;
//       break;
//     }
//   }

//   if (!flag) {
//     ans = n - 1;
//     break;
//   }
// }

// console.log(ans === 0 ? P : ans);

// function getParent(x) {
//   if (x === parents[x]) return x;
//   else return (parents[x] = getParent(parents[x]));
// }

// function unionParent(a, b) {
//   a = getParent(a);
//   b = getParent(b);

//   if (a > b) parents[a] = b;
//   else if (a < b) parents[b] = a;
// }
