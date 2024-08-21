const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const obj = {};

const N = +inputs[0];
const result = [];

for (let i = 1; i <= N; i++) {
  const arr = inputs[i].split(' ');

  isFind = false;
  for (let j = 0; j < arr.length; j++) {
    if (obj[arr[j][0].toLowerCase()] === undefined) {
      obj[arr[j][0].toLowerCase()] = true;
      isFind = true;
      arr[j] = arr[j].replace(arr[j][0], `[${arr[j][0]}]`);
      result.push(arr.join(' '));
      break;
    }
  }

  if (isFind) continue;

  for (let j = 0; j < inputs[i].length; j++) {
    if (inputs[i][j] === ' ') continue;
    if (obj[inputs[i][j].toLowerCase()] === undefined) {
      obj[inputs[i][j].toLowerCase()] = true;
      isFind = true;
      result.push(inputs[i].replace(inputs[i][j], `[${inputs[i][j]}]`));
      break;
    }
  }

  if (!isFind) result.push(inputs[i]);
}

console.log(result.join('\n'));
