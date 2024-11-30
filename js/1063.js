const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const dy = {
  R: 0,
  L: 0,
  B: 1,
  T: -1,
  RT: -1,
  LT: -1,
  RB: 1,
  LB: 1,
};

const dx = {
  R: 1,
  L: -1,
  B: 0,
  T: 0,
  RT: 1,
  LT: -1,
  RB: 1,
  LB: -1,
};

const splited = getLine().split(' ');
const kingLoc = stringLocToNumberLoc(splited[0].split(''));
const rockLoc = stringLocToNumberLoc(splited[1].split(''));
const N = +splited[2];

for (let i = 0; i < N; i++) {
  const command = getLine();

  const ny = kingLoc[1] + dy[command];
  const nx = kingLoc[0] + dx[command];

  if (!inRange(ny, nx)) continue;

  if (ny === rockLoc[1] && nx === rockLoc[0]) {
    const rny = rockLoc[1] + dy[command];
    const rnx = rockLoc[0] + dx[command];

    if (!inRange(rny, rnx)) continue;

    rockLoc[1] = rny;
    rockLoc[0] = rnx;
  }

  kingLoc[1] = ny;
  kingLoc[0] = nx;
}

console.log(numberLocToStringLoc(kingLoc));
console.log(numberLocToStringLoc(rockLoc));

function stringLocToNumberLoc(loc) {
  return [loc[0].charCodeAt(0) - 'A'.charCodeAt(0) + 1, 9 - +loc[1]];
}

function numberLocToStringLoc(loc) {
  return [String.fromCharCode('A'.charCodeAt(0) + loc[0] - 1), (9 - loc[1]).toString()].join('');
}

function inRange(y, x) {
  return 1 <= y && y <= 8 && 1 <= x && x <= 8;
}
