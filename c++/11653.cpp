#include <iostream>

using namespace std;

int main(){
  int n, k = 2;
  cin >> n;

  while(true){
    if(n == 1){
      break;
    }
    if(n%k == 0){
      n /= k;
      cout << k << '\n';
    }else{
      k+=1;
    }
  }

  return 0;
}