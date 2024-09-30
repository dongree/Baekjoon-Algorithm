#include <iostream>

using namespace std;

// dp[i][j] : 길이가 i이고 마지막번째자리가 j인 오르막 수의 개수
int dp[1001][10];

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 0; i < 10; i++) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= N; i++) {
    dp[i][0] = 1;
    for (int j = 1; j < 10; j++) {
      dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
    }
  }

  int result = 0;
  for (int i = 0; i < 10; i++) {
    result += dp[N][i];
  }
  cout << result % 10007;

  return 0;
}