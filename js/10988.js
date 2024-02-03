// 1번 풀이
const fs = require('fs');

const s = fs.readFileSync('/dev/stdin').toString().trim();

let start = 0;
let end = s.length - 1;
let answer = 1;

while (start <= end) {
  if (s[start] !== s[end]) {
    answer = 0;
    break;
  }
  start++;
  end--;
}

console.log(answer);

// 2번 풀이
// const fs = require('fs');

// const s = fs.readFileSync('example.txt').toString();

// const rev = s.split('').reverse().join('');

// console.log(s === rev ? 1 : 0);
