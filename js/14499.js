const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');

let [N, M, y, x, k] = inputs[0].split(' ').map(Number);

const dice = [0, 0, 0, 0, 0, 0]; // 맨위, 북, 동, 서, 남, 맨뒤

const dy = [0, 0, -1, 1];
const dx = [1, -1, 0, 0];
const answer = [];

const map = [];

for (let i = 1; i <= N; i++) {
  const subArr = inputs[i].split(' ').map(Number);
  map.push(subArr);
}

const commands = inputs[N + 1].split(' ').map(Number);

commands.forEach((cmd) => {
  const ny = y + dy[cmd - 1];
  const nx = x + dx[cmd - 1];

  if (inRange(ny, nx)) {
    moveDice(cmd);
    y = ny;
    x = nx;
    answer.push(dice[0]);
    if (map[ny][nx] === 0) {
      map[ny][nx] = dice[5];
    } else {
      dice[5] = map[ny][nx];
      map[ny][nx] = 0;
    }
  }
});

console.log(answer.join('\n'));
// console.log(commands);

function moveDice(direction) {
  let temp;
  switch (direction) {
    case 1:
      temp = dice[0];
      dice[0] = dice[3];
      dice[3] = dice[5];
      dice[5] = dice[2];
      dice[2] = temp;
      break;
    case 2:
      temp = dice[0];
      dice[0] = dice[2];
      dice[2] = dice[5];
      dice[5] = dice[3];
      dice[3] = temp;
      break;
    case 3:
      temp = dice[0];
      dice[0] = dice[4];
      dice[4] = dice[5];
      dice[5] = dice[1];
      dice[1] = temp;
      break;
    case 4:
      temp = dice[0];
      dice[0] = dice[1];
      dice[1] = dice[5];
      dice[5] = dice[4];
      dice[4] = temp;
      break;
  }
}

function inRange(y, x) {
  return 0 <= y && y < N && 0 <= x && x < M;
}
