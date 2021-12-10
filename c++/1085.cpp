#include <iostream>

using namespace std;

int main(){
  int x, y, w, h, minValue;
  cin >> x >> y>> w>> h;

  minValue = min(min(x,y), min(w-x, h-y));
  
  cout << minValue;
  return 0;
}