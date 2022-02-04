#include <iostream>

using namespace std;

int main(){
  int n;
  int dp[10001] = {0,};
  cin >> n;
  for(int i=1; i<=n; i++){
    int a;
    cin >> a;
    int max = a;
    for(int j=1; j<=i/2; j++){
      if(max < dp[j]+dp[i-j]){
        max = dp[j]+dp[i-j];
      }
    }
    dp[i] = max;
  }
  cout << dp[n];
  return 0;
}