const fs = require('fs');

const [N, M, K] = fs.readFileSync('example.txt').toString().trim().split(' ').map(Number);

const on = Math.min(M, K);
const xn = Math.min(N - M, N - K);

console.log(on + xn);
