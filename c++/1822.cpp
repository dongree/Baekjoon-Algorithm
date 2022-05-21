#include <iostream>
#include <map>

using namespace std;

int main(){
  int nA, nB;
  cin >> nA >> nB;
  map<int, bool> m;
  long long a;
  while(nA--){
    cin >> a;
    m[a] = true;
  }
  while(nB--){
    cin >> a;
    m.erase(a);
  }
  cout << m.size() << '\n';
  for(auto iter : m){
    cout << iter.first << ' ';
  }

  return 0;
}