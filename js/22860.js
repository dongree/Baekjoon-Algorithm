const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const [N, M] = getLine().split(' ').map(Number);

const paths = {};

let T = N + M;
while (T--) {
  const [P, F, C] = getLine().split(' ');
  if (C === '1') {
    if (paths[P] === undefined) paths[P] = { folders: [F], files: [] };
    else paths[P]['folders'].push(F);
  } else {
    if (paths[P] === undefined) paths[P] = { folders: [], files: [F] };
    else paths[P]['files'].push(F);
  }
}

const ans = [];

let Q = getLine();

while (Q--) {
  const q = getLine().split('/');
  const files = [];

  dfs(q[q.length - 1]);

  const fileNums = files.length;
  const fileTypeNums = new Set(files).size;

  ans.push([fileTypeNums, fileNums]);

  function dfs(q) {
    if (paths[q] === undefined) return;
    files.push(...paths[q]['files']);

    paths[q]['folders'].forEach((forder) => {
      dfs(forder);
    });
  }
}

console.log(ans.map((e) => e.join(' ')).join('\n'));
