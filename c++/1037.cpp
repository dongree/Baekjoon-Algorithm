#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n;
  int divisors[50];
  cin >> n;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    divisors[i] = a;
  }
  sort(divisors, divisors+n);

  cout << divisors[0]*divisors[n-1];
  return 0;
}