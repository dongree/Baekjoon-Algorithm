#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n,k,l;
int arr[101][101];
char dir[10001];

// 동, 남, 서, 북
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int dir_num=0;

// 빈 곳은 0 사과는 1 뱀은 2

queue<pair<int, int>> snake;

bool inRange(int y, int x){
  return(0<y&&y<=n&&0<x&&x<=n);
}

int main(){
  cin >> n >> k;
  int r,c;
  while(k--){
    cin >> r >> c;
    arr[r][c] = 1;
  };
  cin >> l;
  int tt;
  for(int i=0; i<l; i++){
    cin >> tt;
    cin >> dir[tt];
  }

  arr[1][1] = 2;
  snake.push(make_pair(1,1));
  int y=1;
  int x=1;
  int t=0;
  while(true){
    int ny=y+dy[dir_num];
    int nx=x+dx[dir_num];
    t++;
    if(!inRange(ny, nx) || arr[ny][nx]==2) break;
    if(arr[ny][nx]==0){
      arr[snake.front().first][snake.front().second] = 0;
      snake.pop();
    }
    arr[ny][nx]=2;
    snake.push(make_pair(ny, nx));
    y=ny;
    x=nx;
    if(dir[t]=='D') dir_num = (dir_num+1)%4;
    else if(dir[t]=='L') dir_num = (dir_num+3)%4;
  }
  cout << t;
  return 0;
}
