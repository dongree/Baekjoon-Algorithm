#include <iostream>
#include <string>

using namespace std;

char board[50][50];

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    for(int j=0; j<n; j++){
      board[i][j] = s[j];
    }
  }
  int max = 1;
  char temp1, temp2;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<2; k++){
        if(k==0&&j!=n-1){
          temp1 = board[i][j];
          temp2 = board[i][j+1];
          board[i][j] =temp2;
          board[i][j+1] = temp1;
        }else if(k==1&&i!=n-1){
          temp1 = board[i][j];
          temp2 = board[i+1][j];
          board[i][j] =temp2;
          board[i+1][j] = temp1;
        }else continue;

        int cnt;
        for(int p=0; p<n; p++){
          cnt = 1;
          for(int q=0; q<n-1; q++){
            if(board[p][q]!=board[p][q+1]){
              if(cnt > max) max = cnt;
              cnt = 1;
            }else{
              cnt++;
              if(q==n-2 && cnt > max) max = cnt;
            };
          }
        }
        
        for(int q=0; q<n; q++){
          cnt=1;
          for(int p=0; p<n-1; p++){
            if(board[p][q]!=board[p+1][q]){
              if(cnt > max) max = cnt;
              cnt = 1;
            }else{
              cnt++;
              if(p==n-2 && cnt > max) max = cnt;
            }
          }
        }
        if(k==0){
          board[i][j] = temp1;
          board[i][j+1] = temp2;
        }else{
          board[i][j] = temp1;
          board[i+1][j] = temp2;
        }
      }
    }
  }
  cout << max;
  return 0;
}
