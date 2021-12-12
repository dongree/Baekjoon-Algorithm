#include <iostream>
#include <string>

using namespace std;

const int M =1234567891;
const int r = 31;

int main(){
  int l;
  long long rr = 1;
  long long result = 0;
  string s;

  cin >> l >> s;

  for(int i=0; i < l; i++){
    result = (result + (s[i]-'a'+1)*rr)%M;
    rr = (rr*r)%M;
  }

  cout << result;
  
  return 0;
}