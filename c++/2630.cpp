#include <iostream>

using namespace std;

int paper[128][128];
int white = 0;
int blue = 0;

void cutPaper(int y, int x, int size){
  bool flag = false;
  int check = paper[y][x];
  for(int i=y; i < y+size; i++){
    for(int j=x; j< x+size; j++){
      if(check != paper[i][j]){
        flag = true;
        break;
      }
    }
    if(flag){
      break;
    }
  }

  if(!flag){
    if(check == 1){
      blue++;
    } else if(check == 0){
      white++;
    }
  }else{
    int half = size/2;
    cutPaper(y, x, half);
    cutPaper(y, x+half, half);
    cutPaper(y+half, x, half);
    cutPaper(y+half, x+half, half);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> paper[i][j];
    }
  }
  cutPaper(0,0,n);

  cout << white << '\n' << blue;
  return 0;
}