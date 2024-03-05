const fs = require('fs');

const inptus = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' '));

let idx = 0;
const getLine = () => inptus[idx++];

let [T] = getLine();
T = +T;

const isPrime = Array(10000).fill(true);

for (let i = 2; i * i < 10000; i++) {
  if (isPrime[i]) {
    for (let j = i * i; j < 10000; j += i) {
      isPrime[j] = false;
    }
  }
}

const answer = [];

while (T--) {
  const isVisited = Array(10000).fill(false);

  const [a, b] = getLine();

  const q = [[a, 0]];
  isVisited[+a] = true;
  let flag = true;

  while (q.length !== 0) {
    const [primeNumber, cnt] = q.shift();

    if (primeNumber === b) {
      answer.push(cnt);
      flag = false;
      break;
    }

    for (let i = 0; i < 4; i++) {
      for (let j = 0; j <= 9; j++) {
        if (i === 0 && j === 0) continue;
        let temp = primeNumber.split('');
        temp[i] = `${j}`;
        temp = temp.join('');
        if (primeNumber !== temp && isPrime[+temp] && !isVisited[+temp]) {
          isVisited[+temp] = true;
          q.push([temp, cnt + 1]);
        }
      }
    }
  }

  if (flag) answer.push('Impossible');
}

console.log(answer.join('\n'));
