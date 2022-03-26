#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int m,n;
  cin >> m >> n;
  for(int i=m; i<=n; i++){
    bool flag = true;
    for(int j=2; j<=sqrt(i); j++){
      if(i%j == 0){
        flag = false;
        break;
      }
    }
    if(i!=1 && flag) cout << i << '\n';
  }
  return 0;
}