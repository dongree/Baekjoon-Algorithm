#include <iostream>

using namespace std;

// 0-별 찍힘, 1-별 안찍힘
int arr[6561][6561];

void removeStar(int y, int x, int n){
  if(n==1) return;
  int nn=n/3;
  for(int i=y+nn; i<y+nn*2; i++){
    for(int j=x+nn; j<x+nn*2; j++){
      arr[i][j]=1;
    }
  }

  removeStar(y,x,nn);
  removeStar(y+nn,x,nn);
  removeStar(y,x+nn,nn);
  removeStar(y+nn*2,x,nn);
  removeStar(y,x+nn*2,nn);
  removeStar(y+nn,x+nn*2,nn);
  removeStar(y+nn*2,x+nn,nn);
  removeStar(y+nn*2,x+nn*2,nn);
}

int main(){
  int n;
  cin >> n;

  removeStar(0,0,n);

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[i][j]==0) cout << '*';
      else cout << ' ';
    }
    cout << '\n';
  }
  return 0;
}

// #include <iostream>

// using namespace std;

// int paper[6561][6561];

// void star(int y, int x, int n){
//   if(n == 0){
//     return;
//   }
//   int d = n/3;
//   for(int i=y+d; i<y+2*d; i++){
//     for(int j=x+d; j<x+2*d; j++){
//       paper[i][j] = 1;
//     }
//   }
  
//   for(int i=0; i<3; i++){
//     for(int j=0; j<3; j++){
//       if(paper[y+i*d][x+j*d] == 0){
//         star(y+i*d,x+j*d,d);
//       }
//     }
//   }
// };

// int main(){
//   int n;
//   cin >> n;

//   star(0,0, n);

//   for(int i=0; i<n; i++){
//     for(int j=0; j<n; j++){
//       if(paper[i][j] == 0){
//         cout << '*';
//       }else{
//         cout << ' ';
//       }
//     }
//     cout << '\n';
//   }

//   return 0;
// }

// #include <iostream>

// using namespace std;

// void star(int y, int x, int n){
//   if(y/n%3 == 1 && x/n%3 == 1){
//     cout << ' ';
//   }else if(n/3 == 0){
//     cout <<  '*';
//   }else{
//     star(y,x,n/3);
//   }
// }

// int main(){
//   int n;
//   cin >> n;
//   for(int i=0; i<n; i++){
//     for(int j=0; j<n; j++){
//       star(i,j,n);
//     }
//     cout << '\n';
//   }

//   return 0;
// }