#include <iostream>

using namespace std;

int main()
{
  int num[8] = {0};

  for(int i=0; i<8; i++){
    cin >> num[i];
  }

  int flag;
  if(num[0]==1){
    flag = 1;
    for(int i=1; i<8; i++){
      if(num[i] != i+1){
        flag = 0;
        break;
      }
    }
  }
  else if(num[0]==8){
    flag = 2;
    for(int i=1; i<8; i++){
      if(num[i] != 8-i){
        flag = 0;
        break;
      }
    }
  }
  else{
    flag = 0;
  }

  if(flag == 0){
      cout << "mixed";
    }
  else if(flag == 1) {
    cout << "ascending";
  }
  else if(flag == 2) {
    cout << "descending";
  }
}

// #include <iostream>

// using namespace std;

// int main(){
//   int num[8] = {};
//   int count = 0;
//   for(int i=0; i<8; i++){
//     cin >> num[i];
//   }
//   for(int i=0; i<7; i++){
//     if(num[i] < num[i+1]){
//       count += 1;
//     } else{
//       count -= 1;
//     }
//   }

//   if(count == 7){
//     cout << "ascending";
//   }
//   else if(count == -7){
//     cout << "descending";
//   }
//   else {
//     cout << "mixed";
//   }
//   return 0;
// }