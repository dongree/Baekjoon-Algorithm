// #include <iostream>
// #include <string>

// using namespace std;

// int picture[64][64];

// void compression(int y, int x, int n){
//   bool flag = true;
//   int check = picture[y][x];

//   for(int i=y; i<y+n; i++){
//     for(int j=x; j<x+n; j++){
//       if(picture[i][j] != check){
//         flag = false;
//         break;
//       }
//     }
//     if(!flag){
//       break;
//     }
//   }

//   if(flag){
//     cout << check;
//   }else{
//     int d = n/2;
//     cout << '(';
//     for(int i=0; i<2; i++){
//       for(int j=0; j<2; j++){
//         compression(y+i*d, x+j*d, d);
//       }
//     }
//     cout << ')';
//   }
// }

// int main(){
//   int n;
//   cin >> n;

//   for(int i=0; i<n; i++){
//     string s;
//     cin >> s;
//     for(int j=0; j<n; j++){
//       picture[i][j] = s[j]-'0';
//     }
//   }

//   compression(0,0,n);
//   return 0;
// }

#include <iostream>
#include <string>

using namespace std;

char board[64][64];

string divide(int y, int x, int n) {
  int oneCnt = 0;
  int zeroCnt = 0;
  for (int i = y; i < y + n; i++) {
    for (int j = x; j < x + n; j++) {
      if (board[i][j] == '0')
        zeroCnt++;
      else
        oneCnt++;
    }
  }

  if (zeroCnt == n * n) return "0";
  if (oneCnt == n * n) return "1";

  int halfN = n / 2;

  return '(' + divide(y, x, halfN) + divide(y, x + halfN, halfN) +
         divide(y + halfN, x, halfN) + divide(y + halfN, x + halfN, halfN) +
         ')';
}

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  cout << divide(0, 0, N);

  cout << 1 / 2;
  return 0;
}
