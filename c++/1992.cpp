#include <iostream>
#include <string>

using namespace std;

int picture[64][64];

void compression(int y, int x, int n){
  bool flag = true;
  int check = picture[y][x];

  for(int i=y; i<y+n; i++){
    for(int j=x; j<x+n; j++){
      if(picture[i][j] != check){
        flag = false;
        break;
      }
    }
    if(!flag){
      break;
    }
  }
  
  if(flag){
    cout << check;
  }else{
    int d = n/2;
    cout << '(';
    for(int i=0; i<2; i++){
      for(int j=0; j<2; j++){
        compression(y+i*d, x+j*d, d);
      }
    }
    cout << ')';
  }
}

int main(){
  int n;
  cin >> n;

  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    for(int j=0; j<n; j++){
      picture[i][j] = s[j]-'0';
    }
  }

  compression(0,0,n);
  return 0;
}