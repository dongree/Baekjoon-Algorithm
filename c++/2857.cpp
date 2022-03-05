#include <iostream>
#include <string>

using namespace std;

int main(){
  bool flag = true;
  for(int i=1; i<=5; i++){
    string s;
    cin >> s;
    if(s.find("FBI") != -1){
      cout << i << '\n';
      flag = false;
    }
  }

  if(flag){
    cout << "HE GOT AWAY!";
  }

  return 0;
}