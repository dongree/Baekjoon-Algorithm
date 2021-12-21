#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, string> p1, pair<int, string> p2){
  return p1.first < p2.first;
}

int main(){
  int n;
  vector<pair<int, string>> v;
  cin >> n;

  for(int i=0; i<n; i++){
    int x;
    string y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }

  stable_sort(v.begin(), v.end(), compare);

  for(pair<int, string> p : v){
    cout << p.first << ' ' << p.second << '\n';
  }

  return 0;
}