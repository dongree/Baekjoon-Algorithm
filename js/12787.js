const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let idx = 0;
const getLine = () => inputs[idx++];

const T = +getLine();

for (let i = 0; i < T; i++) {
  const [cmd, s] = getLine().split(' ');

  if (cmd === '1') console.log(ipToDecimal(s));
  else console.log(decimalToIP(BigInt(s)));
}

function decimalToIP(n) {
  let binary = decimalToBinary(n);
  const result = [];

  while (binary.length !== 64) {
    binary = '0' + binary;
  }

  for (let i = 0; i < 8 * 8; i += 8) {
    const a = binary.substring(i, i + 8);

    let d = 0;
    let k = 1;

    for (let j = a.length - 1; j >= 0; j--) {
      if (a[j] === '1') d += k;
      k *= 2;
    }

    result.push(d);
  }
  return result.join('.');
}

function ipToDecimal(ip) {
  const binary = ipToBinary(ip);

  let result = 0n;
  let k = 1n;
  for (let i = binary.length - 1; i >= 0; i--) {
    if (binary[i] === '1') result += k;
    k *= 2n;
  }

  return result.toString();
}

function decimalToBinary(n) {
  let result = '';
  while (n !== 0n) {
    const k = n % 2n ? '1' : '0';
    n /= 2n;
    result = k + result;
  }

  return result;
}

function ipToBinary(ip) {
  let result = '';
  const arr = ip.split('.');

  for (let i = 0; i < arr.length; i++) {
    let temp = decimalToBinary(BigInt(arr[i]));

    while (temp.length !== 8) {
      temp = '0' + temp;
    }

    result = result += temp;
  }

  return result;
}
