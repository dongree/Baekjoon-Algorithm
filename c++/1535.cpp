#include <iostream>

using namespace std;

int L[21];
int J[21];

int dp[21][101];

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> L[i];
  }
  for (int j = 1; j <= N; j++) {
    cin >> J[j];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= 100; j++) {
      if (L[i] < j) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - L[i]] + J[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[N][100];

  return 0;
}