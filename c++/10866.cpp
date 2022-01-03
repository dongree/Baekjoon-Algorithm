#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n;
  vector<int> v;
  cin >> n;

  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    if(s=="push_front"){
      int a;
      cin >> a;
      v.push_back(a);
      for(int i=v.size()-1; i>0; i--){
          int temp = v[i-1];
          v[i-1] = v[i];
          v[i] = temp;
        }
    } else if(s=="push_back"){
      int a;
      cin >> a;
      v.push_back(a);
    } else if(s=="pop_front"){
      if(v.empty()){
        cout << -1 << '\n';
      }else{
        cout << v.front() << '\n';
        for(int i=0; i<v.size()-1; i++){
          int temp = v[i];
          v[i] = v[i+1];
          v[i+1] = temp;
        }
        v.pop_back();
      }
    } else if(s=="pop_back"){
      if(v.empty()){
        cout << -1 << '\n';
      }else{
        cout << v.back() << '\n';
        v.pop_back();
      }
    } else if(s=="size"){
      cout << v.size() << '\n';
    } else if(s=="empty"){
      cout << v.empty() << '\n';
    } else if(s=="front"){
      if(v.empty()){
        cout << -1 << '\n';
      }else{
        cout << v.front() << '\n';
      }
      
    } else if(s=="back"){
      if(v.empty()){
        cout << -1 << '\n';
      }else{
        cout << v.back() << '\n';
      }
    }
  }

  return 0;
}