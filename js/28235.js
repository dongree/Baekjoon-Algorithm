const fs = require('fs');

const s = fs.readFileSync('example.txt').toString().trim();

if (s === 'SONGDO') console.log('HIGHSCHOOL');
else if (s === 'CODE') console.log('MASTER');
else if (s === '2023') console.log('0611');
else if (s === 'ALGORITHM') console.log('CONTEST');
