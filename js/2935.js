const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const A = BigInt(inputs[0]);
const operator = inputs[1];
const B = BigInt(inputs[2]);

if (operator === '*') console.log((A * B).toString());
else console.log((A + B).toString());
