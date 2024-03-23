const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const translated = {
  'A+': 4.5,
  A0: 4.0,
  'B+': 3.5,
  B0: 3.0,
  'C+': 2.5,
  C0: 2.0,
  'D+': 1.5,
  D0: 1.0,
  F: 0.0,
};

let divide = 0;
let sum = 0;

for (let i = 0; i < inputs.length; i++) {
  const [_, a, grade] = inputs[i].split(' ');
  if (grade === 'P') continue;

  sum += translated[grade] * +a;
  divide += +a;
}

console.log(sum / divide);
