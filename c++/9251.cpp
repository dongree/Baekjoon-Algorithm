#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];

int main() {
  freopen("example.txt", "r", stdin);
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.length();
  int m = s2.length();

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  cout << dp[n][m];

  return 0;
}