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

#include <iostream>

using namespace std;

void star(int y, int x, int n){
  if(y/n%3 == 1 && x/n%3 == 1){
    cout << ' ';
  }else if(n/3 == 0){
    cout <<  '*';
  }else{
    star(y,x,n/3);
  }
}

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      star(i,j,n);
    }
    cout << '\n';
  }

  return 0;
}