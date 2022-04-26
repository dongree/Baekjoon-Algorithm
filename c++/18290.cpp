#include <iostream>

using namespace std;

int arr[11][11];
int isVisited[11][11];

int maxN = -40000;
int n,m,k;

void dfs(int y, int x, int cnt, int sum){
  sum+=arr[y][x];
  cnt++;
  if(cnt==k){
    if(sum>maxN) maxN = sum;
    return;
  }

  isVisited[y][x]++;
  if(y-1>0) isVisited[y-1][x]++;
  if(y+1<=n) isVisited[y+1][x]++;
  if(x-1>0) isVisited[y][x-1]++;
  if(x+1<=m) isVisited[y][x+1]++;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(isVisited[i][j]==0){
        dfs(i, j, cnt, sum);
      }
    }
  }

  isVisited[y][x]--;
  if(y-1>0) isVisited[y-1][x]--;
  if(y+1<=n) isVisited[y+1][x]--;
  if(x-1>0) isVisited[y][x-1]--;
  if(x+1<=m) isVisited[y][x+1]--;
}

int main(){
  cin >> n >> m >> k;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      cin >> arr[i][j];
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      dfs(i, j, 0, 0);
    }
  }

  cout << maxN;
  return 0;
}