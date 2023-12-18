const fs = require('fs');

const n = +fs.readFileSync('/dev/stdin').toString().trim();

console.log(fibonacci(n));

function fibonacci(n) {
  if (n === 0) return 0;
  else if (n === 1) return 1;
  else return fibonacci(n - 1) + fibonacci(n - 2);
}

// memoization
// const memo = [0, 1];
// function fibonacci(n) {
//   if (memo[n] !== undefined) return memo[n];
//   memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
//   return memo[n];
// }
