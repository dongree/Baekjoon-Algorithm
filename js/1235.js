const fs = require('fs');

const [N, ...arr] = fs.readFileSync('example.txt').toString().trim().split('\n');

const sn = arr[0].length;

for (let i = 0; i < sn; i++) {
  const st = new Set();
  for (let j = 0; j < +N; j++) {
    const s = arr[j].substring(sn - i - 1, sn);
    st.add(s);
  }

  if (st.size === +N) {
    console.log(i + 1);
    break;
  }
}
