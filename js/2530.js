const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let [A, B, C] = inputs[0].split(' ').map(Number);
let D = +inputs[1];

const h = Math.floor(D / 3600);
D = D % 3600;
const m = Math.floor(D / 60);
D = D % 60;
const s = D;

C += s;
if (C >= 60) {
  C %= 60;
  B += 1;
}
B += m;
if (B >= 60) {
  B %= 60;
  A += 1;
}
A += h;
A = A % 24;

console.log(A, B, C);
