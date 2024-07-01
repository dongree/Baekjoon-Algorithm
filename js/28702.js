const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let flag = false;
let k;

for (let i = 0; i < 3; i++) {
  if (flag) {
    k += 1;
  }

  if (
    inputs[i] === 'Fizz' ||
    inputs[i] === 'Buzz' ||
    inputs[i] === 'FizzBuzz'
  ) {
    continue;
  }

  k = +inputs[i];
  flag = true;
}
k += 1;

if (k % 3 === 0 && k % 5 === 0) console.log('FizzBuzz');
else if (k % 3 === 0) console.log('Fizz');
else if (k % 5 === 0) console.log('Buzz');
else console.log(k);
