#include <iostream>

using namespace std;

int n, m, cnt;
int map[1001][1001];
bool isVisited[1001] = {false, };

void dfs(int v){
    isVisited[v] = true;
    for(int i=1; i<=n; i++){
      if(!(isVisited[i]) && map[v][i] == 1){
        dfs(i);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> n >> m;

  for(int i=0; i<m; i++){
    int u, v;
    cin >> u >> v;
    map[u][v] = map[v][u] = 1;
  }

  for(int i=1; i<=n; i++){
    if(!(isVisited[i])){
      dfs(i);
      cnt++;
    }
  }

  cout << cnt;
  
  return 0;
}
