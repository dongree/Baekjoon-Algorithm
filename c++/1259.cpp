#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  bool flag;

  while(true){
    flag = true;
    cin >> s;
    if(s == "0"){
      return 0;
    }
    for(int i=0; i<s.length()/2; i++){
      if(s[i] != s[s.length()-1-i]){
        flag = false;
        break;
      }
    }
    if(flag){
      cout << "yes" <<'\n';
    } else{
      cout << "no" << '\n';
    }
  }
  return 0;
}