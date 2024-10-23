// my solution

// const fs = require('fs');

// const target = fs.readFileSync('example.txt').toString().trim();

// const isVisited = Array(10).fill(false);
// const obj = {};

// const arr = target.split('');
// let cnt = 0;

// for (let i = 0; i < arr.length; i++) {
//   isVisited[i] = true;
//   dfs(arr[i], arr[i]);
//   isVisited[i] = false;
// }

// console.log(cnt);

// function dfs(s, id) {
//   if (obj[id]) return;

//   if (s.length === target.length) {
//     if (s === target) {
//       cnt++;
//       obj[id] = true;
//     }
//     return;
//   }

//   for (let i = 0; i < arr.length; i++) {
//     if (isVisited[i]) continue;
//     isVisited[i] = true;
//     dfs(s + arr[i], id + s + arr[i]);
//     dfs(arr[i] + s, id + arr[i] + s);
//     isVisited[i] = false;
//   }
// }

// other solution
const fs = require('fs');

const arr = fs.readFileSync('example.txt').toString().trim().split('');
const N = arr.length;

const set = new Set();

for (let i = 0; i < N; i++) {
  dfs(i, i, arr[i], arr[i]);
}

console.log(set.size);

function dfs(left, right, s, id) {
  if (left === 0 && right === N - 1) {
    set.add(id);
    return;
  }

  if (left >= 1) {
    dfs(left - 1, right, arr[left - 1] + s, id + arr[left - 1] + s);
  }

  if (right < N - 1) {
    dfs(left, right + 1, s + arr[right + 1], id + s + arr[right + 1]);
  }
}
