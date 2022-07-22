#include <iostream>

using namespace std;

int r,c,t;
int arr[51][51];

// 동, 남, 서, 북
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool inRange(int x, int y){
  return (0<x&&x<=c&&0<y&&y<=r);
}

int main(){
  cin >> r >> c >> t;
  for(int i=1; i<=r; i++){
    for(int j=1; j<=c; j++){
      cin >> arr[i][j];
    }
  }

  // 공기청정기 위치 찾기
  int c1Y, c2Y;
  for(int i=1; i<=r; i++){
    if(arr[i][1]==-1){
      c1Y=i;
      c2Y=i+1;
      break;
    }
  }

  while(t--){
    // 미세먼지 확산
    int spread[51][51] = {};
    for(int i=1; i<=r; i++){
      for(int j=1; j<=c; j++){
        if(arr[i][j]>0){
          int cnt=0;
          int dust=arr[i][j]/5;
          for(int k=0; k<4; k++){
            int ny=i+dy[k];
            int nx=j+dx[k];
            if(inRange(nx,ny)&&arr[ny][nx]!=-1){
              spread[ny][nx]+=dust;
              cnt++;
            }
          }
          arr[i][j]-=dust*cnt;
        }
      }
    }

    for(int i=1; i<=r; i++){
      for(int j=1; j<=c; j++){
        arr[i][j]+=spread[i][j];
      }
    }

    // 공기청정기 작동
    int y=c1Y;
    int x=1;
    int dir_num=3;
    while(true){
      int ny=y+dy[dir_num];
      int nx=x+dx[dir_num];
      if(!(0<nx&&nx<=c&&0<ny&&ny<=c1Y)) dir_num=(dir_num+1)%4;
      if(arr[y][x]!=-1) arr[y][x]=arr[y+dy[dir_num]][x+dx[dir_num]];
      if(arr[y+dy[dir_num]][x+dx[dir_num]]==-1){
        arr[y][x]=0;
        break;
      }
      y+=dy[dir_num];
      x+=dx[dir_num];
    }
    y=c2Y;
    x=1;
    dir_num=1;
    while(true){
      int ny=y+dy[dir_num];
      int nx=x+dx[dir_num];
      if(!(0<nx&&nx<=c&&c1Y<ny&&ny<=r)) dir_num=(dir_num-1+4)%4;
      if(arr[y][x]!=-1) arr[y][x]=arr[y+dy[dir_num]][x+dx[dir_num]];
      if(arr[y+dy[dir_num]][x+dx[dir_num]]==-1){
        arr[y][x]=0;
        break;
      }
      y+=dy[dir_num];
      x+=dx[dir_num];
    }
  }

  int result=0;
  for(int i=1; i<=r; i++){
    for(int j=1; j<=c; j++){
      if(arr[i][j]>0) result+=arr[i][j];
    }
  }
  cout << result;
  return 0;
}