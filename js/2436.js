const fs = require('fs');

const [gcd, lcm] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

let k = gcd * lcm;
const dividors = [];
const answer = [1, k];
let min = k + 1;

for (let i = 2; i * i <= gcd * lcm; i++) {
  while (k % i === 0) {
    k /= i;
    dividors.push(i);
  }
}
k = gcd * lcm;

dfs(0, 1);
console.log(answer.sort((a, b) => a - b).join(' '));

function dfs(idx, value) {
  if (getGCD(value, k / value) === gcd && value + k / value < min) {
    min = value + k / value;
    answer[0] = value;
    answer[1] = k / value;
  }

  if (idx === dividors.length) {
    return;
  }

  for (let i = idx; i < dividors.length; i++) {
    dfs(i + 1, value * dividors[i]);
  }
}

function getGCD(a, b) {
  if (a % b === 0) return b;
  else return getGCD(b, a % b);
}
