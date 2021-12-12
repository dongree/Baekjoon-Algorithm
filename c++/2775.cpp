#include <iostream>

using namespace std;

int func(int x, int y){
  if(y == 1){
    return 1;
  }
  else if(x==0){
    return y;
  }
  else{
    return func(x-1, y) + func(x, y-1);
  }
}

int main(){
  int t, k, n, result;
  cin >> t;

  for(int i=0; i < t; i++){
    cin >> k >> n;
    result = func(k, n);
    cout << result << '\n';
  }

  return 0;
}