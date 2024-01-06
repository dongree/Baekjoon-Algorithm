const fs = require('fs');

const inputs = fs.readFileSync('example.txt').toString().trim().split('\n');
const [n, m] = inputs[0].split(' ').map(Number);

const map = [];
for (let i = 1; i <= n; i++) {
  map.push(inputs[i].split(' ').map(Number));
}

const homes = [];
const chickenRestaurants = [];

for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) {
    if (map[i][j] === 1) homes.push([i, j]);
    else if (map[i][j] === 2) chickenRestaurants.push([i, j]);
  }
}

const runningRestaurants = [];

let minChickenDistInCity = Infinity;
dfs(0);
console.log(minChickenDistInCity);

function dfs(idx) {
  if (runningRestaurants.length === m) {
    const chickenDistInCity = homes
      .map((home) => {
        const [homeY, homeX] = home;
        const dists = runningRestaurants.map((restaurant) => {
          const [resY, resX] = restaurant;
          return Math.abs(homeY - resY) + Math.abs(homeX - resX);
        });
        return Math.min(...dists);
      })
      .reduce((prev, curr) => prev + curr, 0);
    if (chickenDistInCity < minChickenDistInCity) {
      minChickenDistInCity = chickenDistInCity;
    }
    return;
  }

  for (let i = idx; i < chickenRestaurants.length; i++) {
    runningRestaurants.push(chickenRestaurants[i]);
    dfs(i + 1);
    runningRestaurants.pop();
  }
}
