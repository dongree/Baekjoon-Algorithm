#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
  if(p1.second == p2.second){
    return p1.first < p2.first;
  }
  return p1.second < p2.second;
}

int main(){
  int n;
  vector<pair<int, int>> v;

  cin >> n;

  for(int i=0; i<n; i++){
    int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }

  sort(v.begin(), v.end(), compare);

  for(pair<int, int> p : v){
    cout << p.first << ' ' << p.second << '\n';
  }

  return 0;
}