#include <iostream>

using namespace std;

int n,m,r,c,dir_num,cnt=0;
int arr[50][50];
bool cleaned[50][50];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

bool inRange(int y, int x){
  return 0<=y&&y<n&&0<=x&&x<m;
}

void clean(int y, int x, int dir_num){
  if(!cleaned[y][x]){
    cnt++;
    cleaned[y][x]=true;
  }
  bool flag = true;
  for(int i=dir_num+3; i>=dir_num; i--){
    int ny=y+dy[i%4];
    int nx=x+dx[i%4];
    if(inRange(ny, nx)&&arr[ny][nx]==0&&!cleaned[ny][nx]){
      flag=false;
      clean(ny,nx,i%4);
      break;
    }
  }
  if(flag&&inRange(y-dy[dir_num],x-dx[dir_num])&&arr[y-dy[dir_num]][x-dx[dir_num]]==0) clean(y-dy[dir_num],x-dx[dir_num],dir_num);
}

int main(){
  cin >> n >> m >> r >> c >> dir_num;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> arr[i][j];
    }
  }
  clean(r, c, dir_num);
  cout << cnt;
  return 0;
}