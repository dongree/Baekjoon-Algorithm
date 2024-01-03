const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];
const dist = inputs[1].split(' ').map((e) => BigInt(e));
const price = inputs[2].split(' ').map((e) => BigInt(e));

let currPrice = price[0];
let answer = 0n;

for (let i = 0; i < n - 1; i++) {
  answer += currPrice * dist[i];
  if (currPrice > price[i + 1]) currPrice = price[i + 1];
}

console.log(String(answer));
