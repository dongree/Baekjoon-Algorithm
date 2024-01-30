const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [n, m] = inputs[0].split(' ').map(Number);
const pay = inputs[1].split(' ').map(Number);

let currProfit = pay.slice(0, m).reduce((a, b) => a + b, 0);
let answer = currProfit;

for (let i = 0; i < n - m; i++) {
  currProfit -= pay[i];
  currProfit += pay[i + m];
  answer = Math.max(answer, currProfit);
}

console.log(answer);
