#include <iostream>
#include <queue>

using namespace std;

int n, m, v;
int map[1001][1001];
bool isVisited[1001] = {false,};
queue<int> q;

void dfs(int v){
  isVisited[v] = true;
  cout << v << " ";
  for(int i=1; i<=n; i++){
    if(map[v][i] && !(isVisited[i])){
      dfs(i);
    }
  }
}

void bfs(int v){
  isVisited[v] = true;
  q.push(v);
  while(!q.empty()){
    v = q.front();
    cout << v << " ";
    q.pop();
    for(int i=1; i<=n; i++){
      if(map[v][i] && !(isVisited[i])){
        q.push(i);
        isVisited[i] = true;
    }
  }
  }
}

int main(){
  cin >> n >> m >> v;

  for(int i=0; i<m; i++){
    int x, y;
    cin >> x >> y;
    map[x][y] = map[y][x] = 1;
  }

  dfs(v);

  for(int i=1; i<=n; i++){
    isVisited[i] = false;
  }
  cout << '\n';

  bfs(v);

  return 0;
}