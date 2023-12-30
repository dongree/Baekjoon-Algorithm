const fs = require('fs');

const inputs = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [s, p] = inputs[0].split(' ').map(Number);
const dna = inputs[1];
const [A, C, G, T] = inputs[2].split(' ').map(Number);

let answer = 0;
const nums = {
  A: 0,
  C: 0,
  G: 0,
  T: 0,
};
for (let i = 0; i < p; i++) {
  nums[dna[i]]++;
}

for (let i = 0; i <= s - p; i++) {
  if (i !== 0) {
    nums[dna[i - 1]]--;
    nums[dna[i + p - 1]]++;
  }
  if (nums['A'] >= A && nums['C'] >= C && nums['G'] >= G && nums['T'] >= T)
    answer++;
}

console.log(answer);
