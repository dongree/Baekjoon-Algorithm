#include <iostream>
#include <string>

using namespace std;

int main(){
  int n, m, count, minValue = 32;
  char board[50][50] = {};
  cin >> n >> m;

  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    for(int j=0; j<m; j++){
      board[i][j] = s[j];
    }
  }

  for(int i=0; i<n-7; i++){
    for(int j=0; j<m-7; j++){
      count = 0;
      for(int a=i; a<i+8; a++){
        for(int b=j; b<j+8; b++){
          if(((a+b)%2 == 0 && board[a][b] == 'B') || (a+b)%2 != 0 && board[a][b] == 'W'){
            count += 1;
          } 
        }
      }
      if(minValue > min(count, 64-count)){
        minValue = min(count, 64-count);
      }
    }
  }
  cout << minValue;
  
  return 0;
}