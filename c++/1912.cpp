#include <iostream>

using namespace std;

int dp[100001] = {-1001,};

int main(){
  int n;
  cin >> n;
  int result = -1001;
  for(int i=1; i<=n; i++){
    int a;
    cin >> a;

    if(i == 1 || a > a+dp[i-1]){
      dp[i] = a;
    }
    else{
      dp[i] = a+dp[i-1];
    }

    if(dp[i] > result){
      result = dp[i];
    }
  }
  cout << result;
  return 0;
}