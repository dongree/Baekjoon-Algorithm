#include <iostream>

using namespace std;
long long dp[100001][3] = {{0,0,0},{1,0,0},{0,1,0},{1,1,1}};
long long sum[100001] = {0,1,1,3};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  for(int i=0; i<t; i++){
    int n;
    cin >> n;
    if(dp[n][0] == 0 && dp[n][1] == 0 && dp[n][2] == 0){
      for(int j=4; j<=n; j++){
        dp[j][0] = (dp[j-1][1] + dp[j-1][2])%1000000009;
        dp[j][1] = (dp[j-2][0] + dp[j-2][2])%1000000009;
        dp[j][2] = (dp[j-3][0] + dp[j-3][1])%1000000009;
        sum[j] = (dp[j][0] + dp[j][1] + dp[j][2])%1000000009;
      }
    }
    cout << sum[n] << '\n';
  }
  return 0;
}