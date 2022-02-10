#include <iostream>

using namespace std;

int m, n, k, cnt;
int map[50][50];
bool isVisited[50][50] = {false, };

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void dfs(int y, int x){
  isVisited[y][x] = true;
  
  for(int i=0; i<4; i++){
    int ny = y+dy[i];
    int nx = x+dx[i];
    if(0<= ny && ny < n && 0 <= nx && nx < m && map[ny][nx] && !(isVisited[ny][nx])){
      dfs(ny, nx);
    }
  }
}

int main(){
  int t;
  cin >> t;

  for(int i=0; i<t; i++){
    cin >> m >> n >> k;

    for(int a=0; a<n; a++){
      for(int b=0; b<m; b++){
        isVisited[a][b] = false;
        map[a][b] = 0;
      }
    }

    for(int j=0; j<k; j++){
      int y, x;
      cin >> x >> y;
      map[y][x] = 1;
    }

    cnt = 0;

    for(int a=0; a<n; a++){
      for(int b=0; b<m; b++){
        if(map[a][b] && !(isVisited[a][b])){
          dfs(a,b);
          cnt++;
        }
      }
    }

    cout << cnt << '\n';
  }

  return 0;
}