#include <iostream>

using namespace std;

int main(){
  int n, count = 0;
  cin >> n;
  while(true){
    if(n%5 == 0){
      count += n/5;
      cout << count;
      break;
    }
    n -=3;
    count += 1;
    if(n < 0){
      cout << -1;
      break;
    }
  }
  
  return 0;
}