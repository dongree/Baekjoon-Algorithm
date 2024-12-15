const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n').map(Number);

const result = [];

for (let i = 0; i < inputs.length - 1; i++) {
  const s = `Objects weighing ${inputs[i].toFixed(2)} on Earth will weigh ${(
    inputs[i] * 0.167
  ).toFixed(2)} on the moon.`;
  result.push(s);
}

console.log(result.join('\n'));
