#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
int arr[9];

void dfs(int cnt){
  if(cnt == m){
    for(int i=0; i<m; i++){
      cout << arr[i]<< ' ';
    }
    cout << '\n';
    return;
  }
  for(int i=0; i<n; i++){
    arr[cnt] = v[i];
    dfs(cnt+1);
  }
}

int main(){
  cin >> n >> m;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  dfs(0);
  return 0;
}