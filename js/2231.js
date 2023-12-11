const fs = require('fs');

const input = fs.readFileSync('/dev/stdin').toString();
const n = input.length;
const numberInput = Number(input);
const start = numberInput - n * 9;

let result = 0;

for (let i = start; i < numberInput; i++) {
  let sum = i;
  const stringValue = i.toString();
  for (let j = 0; j < stringValue.length; j++) {
    sum += Number(stringValue[j]);
  }

  if (sum === numberInput) {
    result = i;
    break;
  }
}

console.log(result);
