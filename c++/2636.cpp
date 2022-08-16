#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int r,c;
int hour = 0;
int cheese[100][100];
bool isVisited[100][100];

// 동, 남, 서, 북 
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

void initVisited(){
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      isVisited[i][j]=false;
    }
  }
}

bool inRange(int y, int x){
  return (0<=y&&y<r&&0<=x&&x<c);
}

int bfs(){
  isVisited[0][0] = true;
  int cnt=0;
  queue<pair<int, int>> q;
  q.push({0,0});
  hour++;
  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for(int i=0; i<4; i++){
      int ny=y+dy[i];
      int nx=x+dx[i];
      if(inRange(ny, nx) && !isVisited[ny][nx]){
        if(cheese[ny][nx]==0) q.push({ny,nx});
        else{
          cheese[ny][nx]=0;
          cnt++;
        }
        isVisited[ny][nx]=true;
      }
    }
  }
  return cnt;
}

int main(){
  cin >> r >> c;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cin >> cheese[i][j];
    }
  }
  int preCheeseCnt;
  while(true){
    initVisited();
    int cheeseCnt = bfs();
    if(cheeseCnt==0){
      cout << hour-1 << '\n' << preCheeseCnt;
      break;
    }else preCheeseCnt=cheeseCnt;
  }
  return 0;
}