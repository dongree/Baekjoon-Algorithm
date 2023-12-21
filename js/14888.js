const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +inputs[0];

const nums = inputs[1].split(' ').map(Number);
const operatorNums = inputs[2].split(' ').map(Number);

let maxValue = -Infinity;
let minValue = Infinity;

dfs(1, nums[0]);

console.log(maxValue ? maxValue : 0);
console.log(minValue ? minValue : 0);

function dfs(idx, result) {
  if (idx === n) {
    if (result > maxValue) maxValue = result;
    if (result < minValue) minValue = result;
    return;
  }
  let temp;
  for (let i = 0; i < 4; i++) {
    if (operatorNums[i] !== 0) {
      operatorNums[i] -= 1;
      switch (i) {
        case 0:
          temp = result + nums[idx];
          break;
        case 1:
          temp = result - nums[idx];
          break;
        case 2:
          temp = result * nums[idx];
          break;
        case 3:
          temp =
            result < 0
              ? -Math.floor(-result / nums[idx])
              : Math.floor(result / nums[idx]);
          break;
      }

      dfs(idx + 1, temp);
      operatorNums[i] += 1;
    }
  }
}
