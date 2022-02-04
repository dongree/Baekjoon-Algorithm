#include <iostream>

using namespace std;

int dp[16];
int t[16];
int p[16];

int main(){
  int n;
  cin >> n;

  for(int i=1; i<=n; i++){
    cin >> t[i] >> p[i];
  }

  for(int i=n; i>=1; i--){
    if(t[i]+i-1 > n){
      dp[i] = dp[i+1];
    }else{
      dp[i] = max(dp[i+1], dp[i+t[i]]+p[i]);
    }
  }

  cout << dp[1];

  return 0;
}