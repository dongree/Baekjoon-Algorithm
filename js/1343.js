// first solution
// const fs = require('fs');

// let s = fs.readFileSync('example.txt').toString().trim();

// s += '.';

// let cnt = 0;
// let result = '';
// let flag = false;
// for (let i = 0; i < s.length; i++) {
//   if (s[i] === '.') {
//     if (cnt >= 4) {
//       const a = Math.floor(cnt / 4);
//       result += 'AAAA'.repeat(a);
//       cnt -= 4 * a;
//     }

//     if (cnt === 2) {
//       result += 'BB';
//     } else if (cnt % 2 === 1) {
//       flag = true;
//       break;
//     }
//     result += '.';

//     cnt = 0;
//   } else cnt++;
// }

// if (flag) console.log(-1);
// else console.log(result.substring(0, s.length - 1));

const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();
const result = s.replace(/XXXX/g, 'AAAA').replace(/XX/g, 'BB');

console.log(result.includes('X') ? -1 : result);
