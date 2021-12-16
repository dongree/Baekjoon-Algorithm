#include <iostream>

using namespace std;

int main(){
  int a, b, d = 2;
  int lcm, gcd = 1;
  cin >> a >> b;

  while(!(d > a || d > b)){
    if(a%d==0 && b%d==0){
      a /= d;
      b /= d;
      gcd *= d;
    } else{
      d += 1;
    }
  }
  lcm = gcd*a*b;

  cout << gcd << '\n';
  cout << lcm << '\n';

  return 0;
}