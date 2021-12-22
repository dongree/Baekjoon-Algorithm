#include <iostream>

using namespace std;

int main(){
  int n, count = 0;
  int k, number = 665;

  cin >> n;

  while(count < n){
    number += 1;
    k = number;
    while(k / 100 != 0){
      if(k % 1000 == 666){
        count += 1;
        break;
      }
      k /= 10;
    }
  }

  cout << number;

  return 0;
}