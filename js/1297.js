const fs = require('fs');

const [D, H, W] = fs.readFileSync('example.txt').toString().trim().split(' ').map(Number);

const k = Math.sqrt(D ** 2 / (1 + (W / H) ** 2));

console.log(Math.floor(k), Math.floor(k * (W / H)));
