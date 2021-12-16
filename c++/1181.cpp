#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string a, string b){
  if(a.length() == b.length()){
    return a < b;
  }
  return a.length() < b.length();
}

int main(){
  vector<string> array;
  int n;
  
  cin >> n;
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    array.push_back(s);
  }
  
  sort(array.begin(), array.end(), compare);
  array.erase(unique(array.begin(), array.end()), array.end());

  for(string a : array){
    cout << a << '\n';
  }
  return 0;
}