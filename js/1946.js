const fs = require('fs');

const inputs = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split('\n')
  .map((e) => e.split(' ').map(Number));

let idx = 0;
const getLine = () => inputs[idx++];

let [T] = getLine();
const answers = [];

while (T--) {
  let [N] = getLine();
  const ranking = [];
  let answer = N;
  let tmep = 0;
  while (N--) {
    ranking.push(getLine());
  }
  ranking.sort((a, b) => a[0] - b[0]);
  ranking.forEach((scores) => {
    const [_, k] = scores;
    if (tmep === 0) {
      tmep = k;
      return;
    }
    if (k > tmep) answer -= 1;
    else tmep = k;
  });
  answers.push(answer);
}

console.log(answers.join('\n'));
