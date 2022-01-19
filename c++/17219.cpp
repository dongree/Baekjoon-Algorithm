#include <iostream>
#include <map>
#include <utility>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  map<string, string> memo;

  for(int i=0; i<n; i++){
    string id, pw;
    cin >> id >> pw;
    memo.insert(make_pair(id, pw));
  }

  for(int i=0; i<m; i++){
    string a;
    cin >> a;
    cout << memo[a] << '\n';
  }

  return 0;
}