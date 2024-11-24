const fs = require('fs');

const [N, m, M, T, R] = fs.readFileSync('example.txt').toString().trim().split(' ').map(Number);

let curr = m;
let flag = false;
let cnt = 0;
let t = 0;

if (M - m < T) {
  console.log(-1);
} else {
  while (true) {
    if (cnt === N) break;
    if (curr + T <= M) {
      curr += T;
      cnt++;
      flag = true;
    } else {
      if (curr - R < m) {
        curr = m;
      } else {
        curr -= R;
      }
    }
    t++;
  }
  console.log(t);
}
