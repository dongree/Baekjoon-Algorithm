const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

const regex = /^(100+1+|01)+$/;

console.log(regex.test(s) ? 'SUBMARINE' : 'NOISE');
