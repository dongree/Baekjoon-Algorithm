#include <iostream>

using namespace std;

int main(){
  int n;
  int k= 1;
  cin >> n;

  if(n==1){
    cout << 1;
    return 0;
  }

  while(n-1>0){
    n = n - (6*k);
    k+=1;
  }

  cout << k;
  return 0;
}