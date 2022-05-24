#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> v;

bool compare(tuple<int,int,int>a,tuple<int,int,int>b){
  return get<2>(a) > get<2>(b);
}

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int nationN, stuN, score;
    cin >> nationN >> stuN >> score;
    v.push_back(make_tuple(nationN, stuN, score));
  }

  sort(v.begin(), v.end(), compare);

  for(int i=0; i<2; i++){
    cout << get<0>(v[i]) << ' ' << get<1>(v[i]) << '\n';
  }
  if(get<0>(v[0])==get<0>(v[1])){
    for(int i=2; i<n; i++){
      if(get<0>(v[i])!=get<0>(v[0])){
        cout << get<0>(v[i]) << ' ' << get<1>(v[i]) << '\n';
        break;
      }
    }
  }else{
    cout << get<0>(v[2]) << ' ' << get<1>(v[2]) << '\n';
  }
  
  return 0;
}