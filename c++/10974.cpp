#include <iostream>

using namespace std;

int n;
int arr[8];
bool isVisited[9];

void dfs(int cnt){
  if(cnt==n){
    for(int i=0; i<n; i++){
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i=1; i<=n; i++){
    if(!isVisited[i]){
      isVisited[i]=true;
      arr[cnt] = i;
      dfs(cnt+1);
      isVisited[i]=false;
    }
  }
}

int main(){
  cin >> n;
  dfs(0);
  return 0;
}