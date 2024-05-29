const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const N = +inputs[0];
const drinks = inputs[1].split(' ').map(Number);

let ans = 0;
drinks.sort((a, b) => b - a);
ans += drinks[0];

let k = 0;
for (let i = 1; i < drinks.length; i++) {
  k += drinks[i];
}
ans += k / 2;

console.log(ans);
