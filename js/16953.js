const fs = require('fs');

const [A, B] = fs
  .readFileSync('example.txt')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

console.log(bfs());

function bfs() {
  const q = [[1, A]];
  while (q.length !== 0) {
    const [cnt, value] = q.shift();

    if (value === B) {
      return cnt;
    }

    for (let next of [value * 2, value * 10 + 1]) {
      if (next <= B) {
        q.push([cnt + 1, next]);
      }
    }
  }

  return -1;
}
