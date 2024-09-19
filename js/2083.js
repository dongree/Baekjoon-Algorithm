const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const result = [];

for (let i = 0; i < inputs.length - 1; i++) {
  const [name, age, weight] = inputs[i].split(' ');

  if (+age > 17 || +weight >= 80) result.push(`${name} Senior`);
  else result.push(`${name} Junior`);
}

console.log(result.join('\n'));
