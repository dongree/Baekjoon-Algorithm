#include <iostream>

using namespace std;

long long dp[101];

int main(){
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;

  int t;
  cin >> t;
  for(int i=0; i<t; i++){
    int n;
    cin >> n;
    for(int i=4; i<=n; i++){
      dp[i] = dp[i-2]+dp[i-3];
    }
    cout << dp[n] << '\n';
  }

  return 0;
}