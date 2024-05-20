// #1 my solution - dfs
// const fs = require('fs');

// const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

// let idx = 0;
// const getLine = () => inputs[idx++];

// let [N, M] = getLine().split(' ').map(Number);

// // 0 : 아무것도 모름 | 1 : 진실을 앎 | 2: 과장된 사실을 앎
// let isKnowing = Array(N + 1).fill(0);

// getLine()
//   .split(' ')
//   .slice(1)
//   .forEach((e) => {
//     isKnowing[e] = 1;
//   });

// const parties = [];

// for (let i = 0; i < M; i++) {
//   parties.push(getLine().split(' ').slice(1).map(Number));
// }

// let ans = 0;

// dfs(0, 0);

// console.log(ans);

// function dfs(idx, num) {
//   if (idx === M) {
//     ans = Math.max(ans, num);
//     return;
//   }

//   const party = parties[idx];

//   if (existKnowingTruthPerson(party)) {
//     if (existKnowingExagPerson(party)) return;

//     // 진실
//     const temp = [...isKnowing];
//     for (let i = 0; i < party.length; i++) {
//       const p = party[i];
//       isKnowing[p] = 1;
//     }
//     dfs(idx + 1, num);
//     isKnowing = temp;
//   } else {
//     // 과장
//     const temp = [...isKnowing];
//     for (let i = 0; i < party.length; i++) {
//       const p = party[i];
//       isKnowing[p] = 2;
//     }
//     dfs(idx + 1, num + 1);
//     isKnowing = temp;

//     if (existKnowingExagPerson(party)) return;

//     // 진실
//     for (let i = 0; i < party.length; i++) {
//       const p = party[i];
//       isKnowing[p] = 1;
//     }
//     dfs(idx + 1, num);
//     isKnowing = temp;
//   }
// }

// function existKnowingTruthPerson(party) {
//   for (let i = 0; i < party.length; i++) {
//     const p = party[i];
//     if (isKnowing[p] === 1) {
//       return true;
//     }
//   }
//   return false;
// }

// function existKnowingExagPerson(party) {
//   for (let i = 0; i < party.length; i++) {
//     const p = party[i];
//     if (isKnowing[p] === 2) {
//       return true;
//     }
//   }
//   return false;
// }

// #solution2 union-find 풀이
const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

let [N, M] = getLine().split(' ').map(Number);

const parents = Array(N + 1)
  .fill()
  .map((e, i) => i);
const knowingPeople = getLine().split(' ').slice(1).map(Number);

const parties = [];

for (let i = 0; i < M; i++) {
  const party = getLine().split(' ').slice(1).map(Number);
  const a = party[0];
  party.slice(1).forEach((e) => unionParents(a, e));
  parties.push(party);
}

let ans = 0;

for (let i = 0; i < parties.length; i++) {
  const party = parties[i];
  let flag = true;
  a: for (let j = 0; j < party.length; j++) {
    const p = party[j];
    for (let k = 0; k < knowingPeople.length; k++) {
      if (getParents(p) === getParents(knowingPeople[k])) {
        flag = false;
        break a;
      }
    }
  }
  if (flag) {
    ans++;
  }
}

console.log(ans);

function getParents(x) {
  if (x === parents[x]) return x;
  else return (parents[x] = getParents(parents[x]));
}

function unionParents(a, b) {
  a = getParents(a);
  b = getParents(b);
  if (a > b) parents[a] = b;
  else if (a < b) parents[b] = a;
}
