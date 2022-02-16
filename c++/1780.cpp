#include <iostream>

using namespace std;

int n;
int paper[2187][2187];
int cnt[3];

void divide(int y, int x, int n){
  int num = paper[y][x];
  int flag = true;

  for(int i=y; i<y+n; i++){
    for(int j=x; j<x+n; j++){
      if(num != paper[i][j]){
        flag = false;
        break;
      }
    }
    if(!flag){
      break;
    }
  }

  if(flag){
    cnt[num+1]++;
  }else{
    int d = n/3;
    for(int a=0; a<3; a++){
      for(int b=0; b<3; b++){
        divide(y+a*d, x+b*d, d);
      }
    }
  }
}

int main(){
  cin >> n;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> paper[i][j];
    }
  }

  divide(0, 0, n);

  for(int c : cnt){
    cout << c << '\n';
  }
  return 0;
}