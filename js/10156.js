const fs = require('fs');

const [K, N, M] = fs.readFileSync('example.txt').toString().trim().split(' ').map(Number);

const result = K * N - M;

console.log(result < 0 ? 0 : result);
