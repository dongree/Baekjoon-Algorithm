#include <iostream>

using namespace std;

int stairs[301];
int dp[301];

int main(){
  int n;
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> stairs[i];
  }
  dp[1] = stairs[1];
  dp[2] = stairs[1]+stairs[2];
  dp[3] = max(stairs[1]+stairs[3], stairs[2]+stairs[3]);

  for(int i=4; i<=n; i++){
    dp[i] = max(dp[i-2]+stairs[i], dp[i-3]+stairs[i]+stairs[i-1]);
  }

  cout << dp[n];
  return 0;
}