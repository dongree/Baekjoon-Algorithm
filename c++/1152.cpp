#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  int num=0;
  
  getline(cin, s);
  int length = s.length(); 
  
  if(length == 0 || (length == 1 && s[0] == ' ')){
    cout << 0 << endl;
  }
  else{
    for(int i=0; i < length; i++){
      if(s[i] == ' '){
        num += 1;
      }
    }
    if(s[0] == ' '){
      num -=1;
    }
    if(length != 1 && s[length-1] == ' '){
      num -= 1;
    }
    cout << num+1 << endl;
    }
    return 0;   
}