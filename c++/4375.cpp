#include <iostream>

using namespace std;

int main(){
  
  int n;
  while(cin >> n){
    int cnt = 1;
    int one = 1;
    while(true){
      if(one%n == 0){
        break;
      }
      one=10*one+1;
      one%=n;
      cnt++;
    }
    cout << cnt << '\n';
  }

  return 0;
}