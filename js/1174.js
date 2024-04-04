//  내 풀이

// const fs = require('fs');

// const N = +fs.readFileSync('example.txt').toString().trim();
// let cnt = 0;

// dfs(1);

// function dfs(n) {
//   if (cnt === N) return;
//   if (n === 11) {
//     console.log(-1);
//     return;
//   }

//   const arr = [];
//   if (cnt === N) {
//     return;
//   }

//   subDfs(0, 10);
//   dfs(n + 1);

//   function subDfs(k, pre) {
//     if (k === n) {
//       cnt++;
//       if (cnt === N) {
//         console.log(arr.join(''));
//       }
//       return;
//     }

//     for (let i = 0; i < pre; i++) {
//       if (n > 1 && k == 0 && i == 0) continue;
//       if (cnt < N) {
//         arr.push(i);
//         subDfs(k + 1, i);
//         arr.pop();
//       }
//     }
//   }
// }

const fs = require('fs');

const N = +fs.readFileSync('example.txt').toString().trim();
const arr = [];

for (let i = 0; i < 10; i++) {
  dfs(i, 1);
}

arr.sort((a, b) => a - b);

console.log(arr.length >= N ? arr[N - 1] : -1);

function dfs(num, level) {
  if (level > 10) return;
  arr.push(num);
  for (let i = 0; i < num % 10; i++) {
    dfs(num * 10 + i, level + 1);
  }
}
