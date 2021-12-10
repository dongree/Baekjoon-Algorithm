#include <iostream>

using namespace std;

int main(){
  int t, h, w, n, floor, num;

  cin >> t;

  for(int i=0; i<t; i++){
    cin >> h >> w >> n;
    floor = n%h;
    num = n/h+1;
    if(floor == 0){
      floor = h;
      num -= 1;
    }
    cout << floor*100+num << '\n';
  }

  return 0;
}