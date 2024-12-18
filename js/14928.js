const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

console.log((BigInt(s) % 20000303n).toString());
