#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  map<string, int> dic;
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    dic[s]++;
  }

  int max = 0;
  for(auto a : dic){
    if(a.second>max){
      max = a.second;
    }
  }

  vector<string> v;
  for(auto a : dic){
    if(a.second == max){
      v.push_back(a.first);
    }
  }

  if(v.size() > 1){
    sort(v.begin(), v.end());
  }

  cout << v[0];
  return 0;
}