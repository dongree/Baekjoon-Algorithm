#include <iostream>

using namespace std;

int n, m;
int arr[9];
bool isVisited[9] = {false,};

void dfs(int cnt){
  if(cnt==m){
    for(int i=0; i<m; i++){
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for(int i=1; i<=n; i++){
    if(!isVisited[i]){
      isVisited[i] = true;
      arr[cnt]=i;
      dfs(cnt+1);
      isVisited[i] = false;
    }
  }
}

int main(){
  cin >> n >> m;
  dfs(0);
  return 0;
}