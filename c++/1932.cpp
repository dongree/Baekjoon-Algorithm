#include <iostream>

using namespace std;

int dp[500][500];

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
      cin >> dp[i][j];
    }
  }
  for(int i=1; i<n; i++){
    for(int j=0; j<=i; j++){
      if(j==0) dp[i][j] = dp[i-1][0]+dp[i][j];
      else if(j==i) dp[i][j] = dp[i-1][j-1]+dp[i][j];
      else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j])+dp[i][j];
    }
  }
  int maxNum = 0;
  for(int i=0; i<n; i++){
    if(dp[n-1][i]>maxNum) maxNum = dp[n-1][i];
  }
  cout << maxNum;
  return 0;
}