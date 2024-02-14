const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const [N, M] = inputs[0].split(' ').map(Number);
const arr = inputs[1].split(' ').map(Number);

let a = 0;
let b = 0;

let sum = arr[a];
let answer = 0;

while (a < N && b < N) {
  if (sum === M) {
    answer++;
    sum += arr[++b];
  } else if (sum < M) sum += arr[++b];
  else sum -= arr[a++];
}

console.log(answer);
