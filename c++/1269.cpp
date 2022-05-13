#include <iostream>
#include <map>

using namespace std;

int main(){
  int aNum, bNum;
  cin >> aNum >> bNum;
  map<int, bool> m;
  for(int i=0; i<aNum+bNum; i++){
    int k;
    cin >> k;
    if(m[k]==true) m.erase(k);
    else m[k]=true;
  }
  cout << m.size();
  return 0;
}