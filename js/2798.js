const fs = require('fs');

const input = fs.readFileSync('/dev/stdin').toString().split('\n');

const [n, m] = input[0].split(' ').map(Number);
const arr = input[1].split(' ').map(Number);

let result = 0;

for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) {
    for (let k = 0; k < n; k++) {
      if (!(i === j || j === k || i === k)) {
        const sum = arr[i] + arr[j] + arr[k];
        if (sum <= m && result < sum) {
          result = sum;
        }
      }
    }
  }
}

console.log(result);
