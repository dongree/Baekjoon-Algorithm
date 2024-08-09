const fs = require('fs');

const [num, s] = fs.readFileSync('example.txt').toString().trim().split(' ');

const arr = [];

if (num === '1') {
  let temp = '';
  for (let i = 0; i < s.length; i++) {
    if (s[i] === s[i].toUpperCase()) {
      arr.push(temp);
      temp = s[i].toLowerCase();
    } else {
      temp += s[i];
    }
  }
  arr.push(temp);
} else if (num === '2') {
  let temp = '';
  for (let i = 0; i < s.length; i++) {
    if (s[i] === '_') {
      arr.push(temp);
      temp = '';
    } else {
      temp += s[i];
    }
  }
  arr.push(temp);
} else if (num === '3') {
  let temp = s[0].toLowerCase();
  for (let i = 1; i < s.length; i++) {
    if (s[i] === s[i].toUpperCase()) {
      arr.push(temp);
      temp = s[i].toLowerCase();
    } else {
      temp += s[i];
    }
  }
  arr.push(temp);
}

const camel =
  arr[0] +
  arr
    .slice(1)
    .map((e) => e[0].toUpperCase() + e.substring(1))
    .join('');

const snake = arr.join('_');
const pascal = arr.map((e) => e[0].toUpperCase() + e.substring(1)).join('');

console.log(camel);
console.log(snake);
console.log(pascal);
