#include <iostream>
#include <vector>

using namespace std;

int n,m,maxCnt=0;
int arr[500][500];
// bool isVisited[500][500];
vector<int> v;

int dy[2]={0,1};
int dx[2]={1,0};
int dy2[2]={0,1};
int dx2[2]={-1,0};

bool inRange(int y, int x){
  if(!(0<=y&&y<n&&0<=x&&x<m)) return false;
  // else if(isVisited[y][x]) return false;
  return true;
}

void testomino1(int y, int x){
  if(inRange(y+1,x+1)){
    int value=arr[y][x]+arr[y][x+1]+arr[y+1][x]+arr[y+1][x+1];
    maxCnt=max(value,maxCnt);
  }
}

void testomino2(int y, int x){
  if(inRange(y+1,x+2)){
    maxCnt=max(arr[y][x]+arr[y][x+1]+arr[y+1][x+1]+arr[y][x+2],maxCnt);
  }
  if(inRange(y+2,x-1)){
    maxCnt=max(arr[y][x]+arr[y+1][x]+arr[y+1][x-1]+arr[y+2][x],maxCnt);
  }
  if(inRange(y-1,x-2)){
    maxCnt=max(arr[y][x]+arr[y][x-1]+arr[y-1][x-1]+arr[y][x-2],maxCnt);
  }
  if(inRange(y-2,x+1)){
    maxCnt=max(arr[y][x]+arr[y-1][x]+arr[y-1][x+1]+arr[y-2][x],maxCnt);
  }
}

void dfs(int y, int x, int version){
  if(v.size()==4){
    int cnt=0;
    for(int i=0; i<4; i++){
      cnt+=v[i];
    }
    maxCnt=max(cnt,maxCnt);
    return;
  }

  for(int i=0; i<2; i++){
    int ny,nx;
    if(version==1){
      ny=y+dy[i];
      nx=x+dx[i];
    }else{
      ny=y+dy2[i];
      nx=x+dx2[i];
    }
    
    if(inRange(ny, nx)){
      v.push_back(arr[ny][nx]);
      // isVisited[ny][nx]=true;
      dfs(ny, nx, version);
      v.pop_back();
      // isVisited[ny][nx]=false;
    }
  }
}

int main(){

  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> arr[i][j];
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      v.push_back(arr[i][j]);
      dfs(i,j,1);
      v.pop_back();
      testomino1(i,j);
      testomino2(i,j);
    }
  }

  for(int i=0; i<n; i++){
    for(int j=m-1; j>=0; j--){
      v.push_back(arr[i][j]);
      dfs(i,j,2);
      v.pop_back();
    }
  }

  cout << maxCnt;

  return 0;
}