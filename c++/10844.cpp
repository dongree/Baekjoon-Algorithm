#include <iostream>

using namespace std;

long long dp[101][10] = {{0,0,0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,1,1,1}};
long long sum = 9;

int main(){
  int n;
  cin >> n;
  for(int i=2; i<=n; i++){
    sum = 0;
    for(int j=0; j<10; j++){
      if(j==0){
        dp[i][j] = dp[i-1][1]%1000000000;
      }
      else if(j==9){
        dp[i][j] = dp[i-1][8]%1000000000;
      }
      else{
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
      }
      
      sum += dp[i][j];
    }
  }

  cout << sum%1000000000;

  return 0;
}