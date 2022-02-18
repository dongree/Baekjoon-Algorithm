#include <iostream>
#include <cmath>

using namespace std;

int n, r, c, cnt = 0;

void zSearch(int y, int x, int len){
  if(len==1){
    if(y==r && x==c){
      cout << cnt;
      return;
    }
  }

  int d = len/2;

  if(r<y+d && c<x+d){          // 왼쪽 위칸
    zSearch(y, x, d);
  }else if(r<y+d && c>=x+d){   // 오른쪽 위칸
    cnt += pow(d, 2);
    zSearch(y, x+d, d);
  }else  if(r>=y+d && c<x+d){  // 왼쪽 아래칸
    cnt += 2*pow(d, 2);
    zSearch(y+d, x, d);
  }else{                       // 오른쪽 아래칸
    cnt += 3*pow(d, 2);
    zSearch(y+d, x+d, d);
  }
}

int main(){
  cin >> n >> r >> c;

  int len = pow(2, n);
  zSearch(0,0,len);

  return 0;
}