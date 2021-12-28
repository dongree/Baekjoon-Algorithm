#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main(){
  int r;
  cin >> r;

  cout << fixed;
  cout.precision(5);

  cout << r*r*M_PI << '\n';
  cout << r*r*2 << '\n';
  return 0;
}