#include <iostream>
#include <utility>

using namespace std;

int main(){
  int t;
  cin >> t;

  pair<int, int> fibo[40] = {{1,0}, {0,1}};
  
  for(int i=0; i<t; i++){
    int n;
    cin >> n;

    for(int j=2; j<=n; j++){
      fibo[j] = make_pair(fibo[j-1].first+fibo[j-2].first, fibo[j-1].second+fibo[j-2].second);
    }
    cout << fibo[n].first << " " << fibo[n].second << '\n';
  }

  return 0;
}