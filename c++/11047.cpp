#include <iostream>

using namespace std;

int coin[10];

int main(){
  int n, k, cnt = 0;

  cin >> n >> k;
  for(int i=0; i<n; i++){
    cin >> coin[i];
  }

  for(int i=n-1; i>=0; i--){
    if(k >= coin[i]){
      int coinNum = k/coin[i];
      cnt += coinNum;
      k-=coin[i]*coinNum;
    }
  }

  cout << cnt;

  return 0;
}