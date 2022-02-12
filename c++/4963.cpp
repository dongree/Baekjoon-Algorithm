#include <iostream>

using namespace std;

int map[50][50];
bool isVisited[50][50] = {false, };
int w, h, cnt = 0;

int dy[8] = {0,0,1,1,1,-1,-1,-1};
int dx[8] = {1,-1,0,1,-1,0,1,-1};

void dfs(int y, int x){
  isVisited[y][x] = true;

  for(int i=0; i<8; i++){
    int ny = y+dy[i];
    int nx = x+dx[i];
    if(0 <= ny && ny < h && 0 <= nx && nx < w && map[ny][nx] && !(isVisited[ny][nx])){
      dfs(ny, nx);
    }
  }
}

int main(){
  while(true){
    cin >> w >> h;
    if(w==0 && h==0){
      return 0;
    }

    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        map[i][j] = 0;
        isVisited[i][j] = false;
      }
    }


    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        cin >> map[i][j];
      }
    }
    
    cnt = 0;
    
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        if(map[i][j] && !(isVisited[i][j])){
          dfs(i,j);
          cnt++;
        }
      }
    }
    cout << cnt << '\n';
  }
}