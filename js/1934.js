const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const t = +inputs[0];
const arr = [];
for (let i = 1; i <= t; i++) {
  arr.push(inputs[i].split(' ').map(Number));
}

const results = [];

arr.forEach((item) => {
  const [a, b] = item;
  const result = (a * b) / gcd(a, b);
  results.push(result);
});

console.log(results.join('\n'));

// way1
function gcd(a, b) {
  if (a % b === 0) return b;
  else return gcd(b, a % b);
}

// way2
// function gcd(a, b) {
//   while (b !== 0) {
//     const c = a % b;
//     a = b;
//     b = c;
//   }
//   return a;
// }
