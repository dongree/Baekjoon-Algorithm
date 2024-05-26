const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

const MOD = 1000000007n;
let ans = 0n;

const M = +inputs[0];
for (let i = 1; i <= M; i++) {
  const [N, S] = inputs[i].split(' ').map(BigInt);
  ans += getAns(N, S);
  ans %= MOD;
}

console.log(ans.toString());

function getAns(N, S) {
  return (S * mul(N, MOD - 2n)) % MOD;
}

function mul(a, n) {
  if (n === 1n) return a % MOD;
  if (n % 2n === 0n) {
    const temp = mul(a, n / 2n);
    return (temp * temp) % MOD;
  } else {
    return (a * mul(a, n - 1n)) % MOD;
  }
}
