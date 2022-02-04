#include <iostream>

using namespace std;

int main(){
  long long dp[91] = {0,};
  dp[1] = 1;
  dp[2] = 1;

  int n;
  cin >> n;

  for(int i=3; i<=n; i++){
    dp[i] = dp[i-1]+dp[i-2];
  }

  cout << dp[n];

  return 0;
}