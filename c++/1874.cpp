#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
  int n;
  stack<int> s;
  string pm = "";
  int k=0;
  cin >> n;

  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    if(a > k){
      while(a > k){
        s.push(++k);
        pm += '+';
      }
      s.pop();
      pm += '-';
    }
    else{
      bool flag = true;
      if(a != s.top()){
        flag = false;
      }
      s.pop();
      pm += '-';
      if(!flag){
        cout << "NO";
        return 0;
      }
    }
  }

  for(char c : pm){
    cout << c << '\n';
  }
  
  return 0;
}